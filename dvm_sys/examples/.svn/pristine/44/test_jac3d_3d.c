/* Jacobi-3 program */

#include <math.h>
#include <stdio.h>

#define Max(a, b) ((a) > (b) ? (a) : (b))

#define L 256
#define ITMAX 100

int i, j, k, it = 1;
double eps;

FILE *f;

/* 3D arrays block distributed along 3 dimensions */
#pragma dvm array distribute[block][block][block]
double A[L][L][L];
#pragma dvm array align([i][j][k] with A[i][j][k])
double B[L][L][L];

int main(int an, char **as)
{
    DvmType *dvmDesc[2] = {A , B};
    void *scalarPointers[2] = {&eps, &it};
    size_t scalarsSizes[2] = {sizeof(eps), sizeof(it)};

    const char *name = "test_checkpoint_jac_3d";
    int mode = 1;
    dvmh_create_or_bind_control_point(name, 100, mode, dvmDesc, 2, scalarPointers, scalarsSizes, 2);
    dvmh_load_control_point(name);

    if (it == 1) {
        #pragma dvm region
        {
            /* 3D parallel loop with base array A */
            #pragma dvm parallel([i][j][k] on A[i][j][k]) cuda_block(256)
            for (i = 0; i < L; i++)
                for (j = 0; j < L; j++)
                    for (k = 0; k < L; k++) {
                        A[i][j][k] = 0;
                        if (i == 0 || j == 0 || k == 0 || i == L - 1 || j == L - 1 || k == L - 1)
                            B[i][j][k] = 0;
                        else
                            B[i][j][k] = 4 + i + j + k;
                    }
        }
    } else {
        printf("Initial: it=%4i   eps=%e\n", it, eps);
    }

    /* iteration loop */
    for (; it <= ITMAX; it++)
    {
        if (it % 10 == 0) dvmh_save_control_point(name);
        eps = 0;
        #pragma dvm actual(eps)

        #pragma dvm region
        {
        /* Parallel loop with base array A */
        /* calculating maximum in variable eps */
        #pragma dvm parallel([i][j][k] on A[i][j][k]) reduction(max(eps)), cuda_block(256)
        for (i = 1; i < L - 1; i++)
            for (j = 1; j < L - 1; j++)
                for (k = 1; k < L - 1; k++)
                {
                    double tmp = fabs(B[i][j][k] - A[i][j][k]);
                    eps = Max(tmp, eps);
                    A[i][j][k] = B[i][j][k];
                }

        /* Parallel loop with base array B and */
        /* with prior updating shadow elements of array A */
        #pragma dvm parallel([i][j][k] on B[i][j][k]) shadow_renew(A), cuda_block(256)
        for (i = 1; i < L - 1; i++)
            for (j = 1; j < L - 1; j++)
                for (k = 1; k < L - 1; k++)
                    B[i][j][k] = (A[i - 1][j][k] + A[i][j - 1][k] + A[i][j][k - 1] + A[i][j][k + 1] + A[i][j + 1][k] + A[i + 1][j][k]) / 6.0;
        }

        #pragma dvm get_actual(eps)
        printf("it=%4i   eps=%e\n", it, eps);
    }

    f = fopen("jacobi.dat", "wb");
    #pragma dvm get_actual(B)
    fwrite(B, sizeof(double), L * L * L, f);
    fclose(f);

    return 0;
}
