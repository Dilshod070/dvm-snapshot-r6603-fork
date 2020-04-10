#include "../tools/pppa/src/statlist.h"
//#include "../tools/pppa/src/integration.h"
#include <iostream>
#include <string>

int main(int argv, char ** argc) {
  CStat s;
	try {
//		printf("go to init\n");
		s.init((char*)("sts.gz+"));
        json j;
        s.to_json(j);
        char *res1, *res2;

//        const char * s2 = "{\"inter\":[{\"id\":{\"expr\":2000000000,\"nenter\":1.0,\"nlev\":0,\"nline\":20,\"nline_end\":87,\"pname\":\"jac2d_no_output.c\",\"t\":21},\"times\":{\"comm\":3.4757325649261475,\"comm_start\":0.0,\"efficiency\":0.9550335682227789,\"exec_time\":39.77296304702759,\"gpu_time_lost\":0.0,\"gpu_time_prod\":0.0,\"idle\":0.530217170715332,\"insuf\":3.1478431820869446,\"insuf_sys\":1.5746142268180847,\"insuf_user\":1.5732289552688599,\"load_imb\":0.6203498244285583,\"lost_time\":7.153792917728424,\"nproc\":4,\"overlap\":0.0001239776611328125,\"prod_cpu\":151.41318786144257,\"prod_io\":0.0015636682510375977,\"prod_sys\":0.523307740688324,\"real_comm\":0.0,\"synch\":3.168708562850952,\"sys_time\":159.09185218811035,\"thr_sys_time\":0.0,\"thr_user_time\":0.0,\"threadsOfAllProcs\":4,\"time_var\":3.2875447273254395}},{\"id\":{\"expr\":0,\"nenter\":1.0,\"nlev\":1,\"nline\":25,\"nline_end\":41,\"pname\":\"jac2d_no_output.c\",\"t\":23},\"times\":{\"comm\":0.0,\"comm_start\":0.0,\"efficiency\":0.9906749709001953,\"exec_time\":2.5974280834198,\"gpu_time_lost\":0.0,\"gpu_time_prod\":0.0,\"idle\":0.09276914596557617,\"insuf\":0.0041152238845825195,\"insuf_sys\":0.002048313617706299,\"insuf_user\":0.0020669102668762207,\"load_imb\":0.0942772626876831,\"lost_time\":0.09688436985015869,\"nproc\":4,\"overlap\":0.0,\"prod_cpu\":10.292145192623138,\"prod_io\":0.0,\"prod_sys\":0.0006827712059020996,\"real_comm\":0.0,\"synch\":0.0,\"sys_time\":10.3897123336792,\"thr_sys_time\":0.0,\"thr_user_time\":0.0,\"threadsOfAllProcs\":4,\"time_var\":0.0}},{\"id\":{\"expr\":11,\"nenter\":20.0,\"nlev\":2,\"nline\":51,\"nline_end\":60,\"pname\":\"jac2d_no_output.c\",\"t\":23},\"times\":{\"comm\":3.253131628036499,\"comm_start\":0.0,\"efficiency\":0.938293852186046,\"exec_time\":21.65014410018921,\"gpu_time_lost\":0.0,\"gpu_time_prod\":0.0,\"idle\":2.0638887882232666,\"insuf\":0.0267675518989563,\"insuf_sys\":0.01176595687866211,\"insuf_user\":0.01500159502029419,\"load_imb\":0.5726998448371887,\"lost_time\":5.343787968158722,\"nproc\":4,\"overlap\":8.797645568847656e-05,\"prod_cpu\":81.2528664469719,\"prod_io\":0.0,\"prod_sys\":0.003921985626220703,\"real_comm\":0.0,\"synch\":0.04774832725524902,\"sys_time\":86.60057640075684,\"thr_sys_time\":0.0,\"thr_user_time\":0.0,\"threadsOfAllProcs\":4,\"time_var\":0.047759056091308594}},{\"id\":{\"expr\":12,\"nenter\":20.0,\"nlev\":2,\"nline\":61,\"nline_end\":62,\"pname\":\"jac2d_no_output.c\",\"t\":23},\"times\":{\"comm\":0.0,\"comm_start\":0.0,\"efficiency\":0.09349327040727146,\"exec_time\":0.001363992691040039,\"gpu_time_lost\":0.0,\"gpu_time_prod\":0.0,\"idle\":0.0034155845642089844,\"insuf\":0.001530289649963379,\"insuf_sys\":0.0014839768409729004,\"insuf_user\":4.6312808990478516e-05,\"load_imb\":0.0008538961410522461,\"lost_time\":0.004945874214172363,\"nproc\":4,\"overlap\":0.0,\"prod_cpu\":1.5437602996826172e-05,\"prod_io\":0.0,\"prod_sys\":0.0004946589469909668,\"real_comm\":0.0,\"synch\":0.0,\"sys_time\":0.005455970764160156,\"thr_sys_time\":0.0,\"thr_user_time\":0.0,\"threadsOfAllProcs\":4,\"time_var\":0.0}},{\"id\":{\"expr\":1,\"nenter\":20.0,\"nlev\":1,\"nline\":50,\"nline_end\":63,\"pname\":\"jac2d_no_output.c\",\"t\":23},\"times\":{\"comm\":3.253131628036499,\"comm_start\":0.0,\"efficiency\":0.9382872912606198,\"exec_time\":21.650550603866577,\"gpu_time_lost\":0.0,\"gpu_time_prod\":0.0,\"idle\":2.0616848468780518,\"insuf\":0.029640018939971924,\"insuf_sys\":0.01376044750213623,\"insuf_user\":0.015879571437835693,\"load_imb\":0.572148859500885,\"lost_time\":5.344456493854523,\"nproc\":4,\"overlap\":8.797645568847656e-05,\"prod_cpu\":81.25315910577774,\"prod_io\":0.0,\"prod_sys\":0.00458681583404541,\"real_comm\":0.0,\"synch\":0.04774832725524902,\"sys_time\":86.60220241546631,\"thr_sys_time\":0.0,\"thr_user_time\":0.0,\"threadsOfAllProcs\":4,\"time_var\":0.047759056091308594}}],\"iscomp\":true,\"nproc\":4,\"proc\":[{\"node_name\":\"MacBook-Penek.local\",\"test_time\":1.727762},{\"node_name\":\"MacBook-Penek.local\",\"test_time\":5.21501872804197e-310},{\"node_name\":\"MacBook-Penek.local\",\"test_time\":5.21501872804513e-310},{\"node_name\":\"MacBook-Penek.local\",\"test_time\":5.2150187280483e-310}]}";
        std::cout << j << std::endl << std::endl;
//        const char * s1 = "{\"nproc\":4,\"iscomp\":true,\"proc\":[{\"node_name\":\"MacBook-Penek.local\",\"test_time\":1.5134299999999998},{\"node_name\":\"MacBook-Penek.local\",\"test_time\":5.21501811231286E-310},{\"node_name\":\"MacBook-Penek.local\",\"test_time\":5.2150181123159709E-310},{\"node_name\":\"MacBook-Penek.local\",\"test_time\":5.2150181123191823E-310}],\"inter\":[{\"id\":{\"nlev\":0,\"t\":21,\"expr\":2000000000,\"nline\":20,\"nline_end\":83,\"nenter\":1.0,\"pname\":\"jac2d.c\"},\"times\":{\"prod_cpu\":0.32072204351425171,\"prod_sys\":0.0013052821159362793,\"prod_io\":0.0,\"prod\":0.0,\"exec_time\":0.4253990650177002,\"sys_time\":1.7015962600708008,\"efficiency\":0.18925013717225081,\"lost_time\":1.3795689344406128,\"insuf\":0.95826780796051025,\"insuf_user\":0.95435196161270142,\"insuf_sys\":0.0039158463478088379,\"comm\":0.011639118194580078,\"real_comm\":0.0,\"comm_start\":0.0,\"idle\":0.40966200828552246,\"load_imb\":0.10226333141326904,\"synch\":0.0060858726501464844,\"time_var\":0.0077383518218994141,\"overlap\":1.1920928955078125E-05,\"thr_user_time\":0.0,\"thr_sys_time\":0.0,\"gpu_time_prod\":0.0,\"gpu_time_lost\":0.0,\"nproc\":4,\"threadsOfAllProcs\":4}},{\"id\":{\"nlev\":1,\"t\":23,\"expr\":1,\"nline\":48,\"nline_end\":61,\"nenter\":13.0,\"pname\":\"jac2d.c\"},\"times\":{\"prod_cpu\":0.0016168951988220215,\"prod_sys\":0.00041013956069946289,\"prod_io\":0.0,\"prod\":0.0,\"exec_time\":0.0037238597869873047,\"sys_time\":0.014895439147949219,\"efficiency\":0.1360842563544401,\"lost_time\":0.012868404388427734,\"insuf\":0.0029754638671875,\"insuf_user\":0.0017450451850891113,\"insuf_sys\":0.0012304186820983887,\"comm\":0.0068995952606201172,\"real_comm\":0.0,\"comm_start\":0.0,\"idle\":0.0029933452606201172,\"load_imb\":0.000331878662109375,\"synch\":0.0031926631927490234,\"time_var\":0.0031957626342773438,\"overlap\":8.106231689453125E-06,\"thr_user_time\":0.0,\"thr_sys_time\":0.0,\"gpu_time_prod\":0.0,\"gpu_time_lost\":0.0,\"nproc\":4,\"threadsOfAllProcs\":4}},{\"id\":{\"nlev\":2,\"t\":23,\"expr\":11,\"nline\":49,\"nline_end\":58,\"nenter\":13.0,\"pname\":\"jac2d.c\"},\"times\":{\"prod_cpu\":0.0016019344329833984,\"prod_sys\":0.00033086538314819336,\"prod_io\":0.0,\"prod\":0.0,\"exec_time\":0.0036263465881347656,\"sys_time\":0.014505386352539063,\"efficiency\":0.13324704142011834,\"lost_time\":0.012572586536407471,\"insuf\":0.0026927590370178223,\"insuf_user\":0.0017001628875732422,\"insuf_sys\":0.00099259614944458,\"comm\":0.0068995952606201172,\"real_comm\":0.0,\"comm_start\":0.0,\"idle\":0.0029802322387695313,\"load_imb\":0.00033789873123168945,\"synch\":0.0031926631927490234,\"time_var\":0.0031957626342773438,\"overlap\":8.106231689453125E-06,\"thr_user_time\":0.0,\"thr_sys_time\":0.0,\"gpu_time_prod\":0.0,\"gpu_time_lost\":0.0,\"nproc\":4,\"threadsOfAllProcs\":4}},{\"id\":{\"nlev\":2,\"t\":23,\"expr\":12,\"nline\":59,\"nline_end\":60,\"nenter\":13.0,\"pname\":\"jac2d.c\"},\"times\":{\"prod_cpu\":4.9471855163574219E-06,\"prod_sys\":3.2305717468261719E-05,\"prod_io\":0.0,\"prod\":0.0,\"exec_time\":4.4107437133789063E-05,\"sys_time\":0.00017642974853515625,\"efficiency\":0.21114864864864866,\"lost_time\":0.00013917684555053711,\"insuf\":0.00011175870895385742,\"insuf_user\":1.4841556549072266E-05,\"insuf_sys\":9.6917152404785156E-05,\"comm\":0.0,\"real_comm\":0.0,\"comm_start\":0.0,\"idle\":2.7418136596679688E-05,\"load_imb\":6.8545341491699219E-06,\"synch\":0.0,\"time_var\":0.0,\"overlap\":0.0,\"thr_user_time\":0.0,\"thr_sys_time\":0.0,\"gpu_time_prod\":0.0,\"gpu_time_lost\":0.0,\"nproc\":4,\"threadsOfAllProcs\":4}},{\"id\":{\"nlev\":1,\"t\":23,\"expr\":2,\"nline\":65,\"nline_end\":70,\"nenter\":13.0,\"pname\":\"jac2d.c\"},\"times\":{\"prod_cpu\":0.0018294453620910645,\"prod_sys\":0.00076007843017578125,\"prod_io\":0.0,\"prod\":0.0,\"exec_time\":0.0035240650177001953,\"sys_time\":0.014096260070800781,\"efficiency\":0.18370289560922806,\"lost_time\":0.011506736278533936,\"insuf\":0.00453561544418335,\"insuf_user\":0.0022553801536560059,\"insuf_sys\":0.0022802352905273438,\"comm\":0.0047395229339599609,\"real_comm\":0.0,\"comm_start\":0.0,\"idle\":0.002231597900390625,\"load_imb\":0.00039070844650268555,\"synch\":0.0028932094573974609,\"time_var\":0.00454258918762207,\"overlap\":3.814697265625E-06,\"thr_user_time\":0.0,\"thr_sys_time\":0.0,\"gpu_time_prod\":0.0,\"gpu_time_lost\":0.0,\"nproc\":4,\"threadsOfAllProcs\":4}}]}";

        std::cout << "I'm alive\n";

//        if (stat_intersect_((char*) s1, (char*) s2, res1, res2)){
//            printf("not working ((((9 \n\n");
//            return 1;
//        }
//
//        std::cout << res1 << std::endl << std::endl << res2 << std::endl << std::endl;

	}
	catch(...){
		printf("error!");
	}
	printf("ok\n");
	return 0;
}
