#ifndef  _EVENTS_C_
#define  _EVENTS_C_
/*****************/    /*E0000*/
 
/****************************\
*  Define trace event names  *
\****************************/    /*E0001*/

void  events(void)
{
  trc_event( Event0                     )
  trc_event( Event_MeasureStart         )
  trc_event( Event_MeasureFinish        )
  trc_event( DVM_Trace_Start            )
  trc_event( call_rtl_Send              )
  trc_event( ret_rtl_Send               )
  trc_event( call_rtl_Recv              )
  trc_event( ret_rtl_Recv               )
  trc_event( call_rtl_BroadCast         )
  trc_event( ret_rtl_BroadCast          )
  trc_event( call_rtl_Sendnowait        )  
  trc_event( ret_rtl_Sendnowait         )  
  trc_event( call_rtl_Recvnowait        )  
  trc_event( ret_rtl_Recvnowait         )  
  trc_event( call_rtl_Waitrequest       )  
  trc_event( ret_rtl_Waitrequest        )  
  trc_event( call_rtl_Testrequest       )  
  trc_event( ret_rtl_Testrequest        )  
  trc_event( call_rtl_SendA             )  
  trc_event( ret_rtl_SendA              )  
  trc_event( call_rtl_RecvA             )  
  trc_event( ret_rtl_RecvA              )  
  trc_event( call_delrg_                )
  trc_event( ret_delrg_                 )
  trc_event( call_insred_               )
  trc_event( ret_insred_                )
  trc_event( call_bsynch_               )
  trc_event( ret_bsynch_                )
  trc_event( call_arrcpy_               )
  trc_event( ret_arrcpy_                ) 
  trc_event( call_crtda_                ) 
  trc_event( ret_crtda_                 ) 
  trc_event( call_getam_                ) 
  trc_event( ret_getam_                 ) 
  trc_event( call_crtamv_               ) 
  trc_event( ret_crtamv_                ) 
  trc_event( call_align_                ) 
  trc_event( ret_align_                 ) 
  trc_event( call_getps_                ) 
  trc_event( ret_getps_                 ) 
  trc_event( call_saverg_               ) 
  trc_event( ret_saverg_                ) 
  trc_event( call_CreateVMS             ) 
  trc_event( ret_CreateVMS              ) 
  trc_event( call_tstelm_               ) 
  trc_event( ret_tstelm_                ) 
  trc_event( call_rwelm_                ) 
  trc_event( ret_rwelm_                 ) 
  trc_event( call_rlocel_               ) 
  trc_event( ret_rlocel_                ) 
  trc_event( call_delda_                ) 
  trc_event( ret_delda_                 ) 
  trc_event( call_delobj_               ) 
  trc_event( ret_delobj_                ) 
  trc_event( call_copelm_               ) 
  trc_event( ret_copelm_                ) 
  trc_event( call_elmcpy_               ) 
  trc_event( ret_elmcpy_                ) 
  trc_event( call_wlocel_               ) 
  trc_event( ret_wlocel_                ) 
  trc_event( call_clocel_               ) 
  trc_event( ret_clocel_                ) 
  trc_event( call_GetLocElmAddr         ) 
  trc_event( ret_GetLocElmAddr          ) 
  trc_event( call_getlen_               ) 
  trc_event( ret_getlen_                ) 
  trc_event( call_dvm_fopen             ) 
  trc_event( ret_dvm_fopen              ) 
  trc_event( call_dvm_fclose            ) 
  trc_event( ret_dvm_fclose             ) 
  trc_event( call_dvm_void_vfprintf     ) 
  trc_event( ret_dvm_void_vfprintf      ) 
  trc_event( call_dvm_vfprintf          ) 
  trc_event( ret_dvm_vfprintf           ) 
  trc_event( call_dvm_fwrite            ) 
  trc_event( ret_dvm_fwrite             ) 
  trc_event( call_dvm_fread             ) 
  trc_event( ret_dvm_fread              ) 
  trc_event( call_DisArrRead            ) 
  trc_event( ret_DisArrRead             ) 
  trc_event( call_DisArrWrite           ) 
  trc_event( ret_DisArrWrite            ) 
  trc_event( call_tron_                 ) 
  trc_event( call_delamv_               ) 
  trc_event( ret_delamv_                ) 
  trc_event( call_distr_                ) 
  trc_event( ret_distr_                 ) 
  trc_event( call_crtred_               ) 
  trc_event( ret_crtred_                ) 
  trc_event( call_delred_               )
  trc_event( ret_delred_                ) 
  trc_event( call_RedVar_Done           ) 
  trc_event( ret_RedVar_Done            ) 
  trc_event( call_parloop_Done          ) 
  trc_event( ret_parloop_Done           ) 
  trc_event( call_env_Done              ) 
  trc_event( ret_env_Done               ) 
  trc_event( call_vms_Done              ) 
  trc_event( ret_vms_Done               ) 
  trc_event( call_begbl_                ) 
  trc_event( ret_begbl_                 )
  trc_event( call_endbl_                )
  trc_event( ret_endbl_                 )
  trc_event( call_crtpl_                )
  trc_event( ret_crtpl_                 )
  trc_event( call_mappl_                )
  trc_event( ret_mappl_                 )
  trc_event( call_endpl_                )
  trc_event( ret_endpl_                 )
  trc_event( call_locind_               )
  trc_event( ret_locind_                )
  trc_event( call_tstda_                )
  trc_event( ret_tstda_                 )
  trc_event( call_srmem_                )
  trc_event( ret_srmem_                 )
  trc_event( call_tstio_                )
  trc_event( ret_tstio_                 )
  trc_event( call_getrnk_               )
  trc_event( ret_getrnk_                )
  trc_event( call_getsiz_               )
  trc_event( ret_getsiz_                )
  trc_event( call_dvm_vscanf            )
  trc_event( ret_dvm_vscanf             )
  trc_event( call_realn_                )
  trc_event( ret_realn_                 )
  trc_event( call_redis_                )
  trc_event( ret_redis_                 )
  trc_event( call_arrmap_               )
  trc_event( ret_arrmap_                )
  trc_event( call_red_Sendnowait        )
  trc_event( ret_red_Sendnowait         )
  trc_event( call_red_Recvnowait        )
  trc_event( ret_red_Recvnowait         )
  trc_event( call_red_Waitrequest       )
  trc_event( ret_red_Waitrequest        )
  trc_event( call_setpsw_               )
  trc_event( ret_setpsw_                )
  trc_event( call_red_Testrequest       )
  trc_event( ret_red_Testrequest        )
  trc_event( call_setind_               )
  trc_event( ret_setind_                )
  trc_event( call_locsiz_               )
  trc_event( ret_locsiz_                )
  trc_event( call_shd_Sendnowait        )
  trc_event( ret_shd_Sendnowait         )
  trc_event( call_shd_Recvnowait        )
  trc_event( ret_shd_Recvnowait         )
  trc_event( call_shd_Waitrequest       )
  trc_event( ret_shd_Waitrequest        )
  trc_event( call_imlast_               )
  trc_event( ret_imlast_                )
  trc_event( call_insshd_               )
  trc_event( ret_insshd_                )
  trc_event( call_malign_               )
  trc_event( ret_malign_                )
  trc_event( call_crtrg_                )
  trc_event( ret_crtrg_                 )
  trc_event( call_mrealn_               )
  trc_event( ret_mrealn_                )
  trc_event( call_strtrd_               )
  trc_event( ret_strtrd_                )
  trc_event( call_waitrd_               )
  trc_event( ret_waitrd_                )
  trc_event( call_amvmap_               )
  trc_event( ret_amvmap_                )
  trc_event( call_CreateBoundBuffer     )
  trc_event( ret_CreateBoundBuffer      )
  trc_event( call_getamv_               )
  trc_event( ret_getamv_                )
  trc_event( call_saverv_               )
  trc_event( ret_saverv_                )
  trc_event( call_rstrg_                )
  trc_event( ret_rstrg_                 )
  trc_event( call_exfrst_               )
  trc_event( ret_exfrst_                )
  trc_event( call_dopl_                 )
  trc_event( ret_dopl_                  )
  trc_event( call_dvm_Init              )
  trc_event( ret_dvm_Init               )
  trc_event( call_dvm_Done              )
  trc_event( ret_dvm_Done               )
  trc_event( DVM_Trace_Finish           )
  trc_event( Event_rtl_GetMasterProc    )
  trc_event( Event_rtl_GetCentralProc   )
  trc_event( Event_rtl_GetCurrentProc   )
  trc_event( Event_rtl_GetIOProc        )
  trc_event( call_mdistr_               )
  trc_event( ret_mdistr_                )
  trc_event( call_mredis_               )
  trc_event( ret_mredis_                )
  trc_event( call_delarm_               )
  trc_event( ret_delarm_                )
  trc_event( call_delmvm_               )
  trc_event( ret_delmvm_                )
  trc_event( call_dvm_fscanf            )
  trc_event( ret_dvm_fscanf             )
  trc_event( call_dvm_scanf             )
  trc_event( ret_dvm_scanf              )
  trc_event( call_dvm_vfscanf           )
  trc_event( ret_dvm_vfscanf            )
  trc_event( call_dvm_clearerr          )
  trc_event( ret_dvm_clearerr           )
  trc_event( call_dvm_feof              )
  trc_event( ret_dvm_feof               )
  trc_event( call_dvm_ferror            )
  trc_event( ret_dvm_ferror             )
  trc_event( call_dvm_fflush            )
  trc_event( ret_dvm_fflush             )
  trc_event( call_dvm_fgetc             )
  trc_event( ret_dvm_fgetc              )
  trc_event( call_dvm_fgetpos           )
  trc_event( ret_dvm_fgetpos            )
  trc_event( call_dvm_fgets             )
  trc_event( ret_dvm_fgets              )
  trc_event( call_dvm_fputc             )
  trc_event( ret_dvm_fputc              )
  trc_event( call_dvm_fputs             )
  trc_event( ret_dvm_fputs              )
  trc_event( call_dvm_freopen           )
  trc_event( ret_dvm_freopen            )
  trc_event( call_dvm_fseek             )
  trc_event( ret_dvm_fseek              )
  trc_event( call_dvm_fsetpos           )
  trc_event( ret_dvm_fsetpos            )
  trc_event( call_dvm_ftell             )
  trc_event( ret_dvm_ftell              )
  trc_event( call_dvm_getc              )
  trc_event( ret_dvm_getc               )
  trc_event( call_dvm_getchar           )
  trc_event( ret_dvm_getchar            )
  trc_event( call_dvm_gets              )
  trc_event( ret_dvm_gets               )
  trc_event( call_dvm_putc              )
  trc_event( ret_dvm_putc               )
  trc_event( call_dvm_putchar           )
  trc_event( ret_dvm_putchar            )
  trc_event( call_dvm_puts              )
  trc_event( ret_dvm_puts               )
  trc_event( call_dvm_rewind            )
  trc_event( ret_dvm_rewind             )
  trc_event( call_dvm_setbuf            )
  trc_event( ret_dvm_setbuf             )
  trc_event( call_dvm_setvbuf           )
  trc_event( ret_dvm_setvbuf            )
  trc_event( call_dvm_tmpfile           )
  trc_event( ret_dvm_tmpfile            )
  trc_event( call_dvm_ungetc            )
  trc_event( ret_dvm_ungetc             )
  trc_event( call_dvm_void_fprintf      )
  trc_event( ret_dvm_void_fprintf       )
  trc_event( call_dvm_fprintf           )
  trc_event( ret_dvm_fprintf            )
  trc_event( call_dvm_void_printf       )
  trc_event( ret_dvm_void_printf        )
  trc_event( call_dvm_printf            )
  trc_event( ret_dvm_printf             )
  trc_event( call_dvm_void_vprintf      )
  trc_event( ret_dvm_void_vprintf       )
  trc_event( call_dvm_vprintf           )
  trc_event( ret_dvm_vprintf            )
  trc_event( call_dvm_remove            )
  trc_event( ret_dvm_remove             )
  trc_event( call_dvm_rename            )
  trc_event( ret_dvm_rename             )
  trc_event( call_dvm_tmpnam            )
  trc_event( ret_dvm_tmpnam             )
  trc_event( call_dvm_close             )
  trc_event( ret_dvm_close              )
  trc_event( call_dvm_fstat             )
  trc_event( ret_dvm_fstat              )
  trc_event( call_dvm_lseek             )
  trc_event( ret_dvm_lseek              )
  trc_event( call_dvm_open              )
  trc_event( ret_dvm_open               )
  trc_event( call_dvm_read              )
  trc_event( ret_dvm_read               )
  trc_event( call_dvm_write             )
  trc_event( ret_dvm_write              )
  trc_event( call_dvm_access            )
  trc_event( ret_dvm_access             )
  trc_event( call_dvm_stat              )
  trc_event( ret_dvm_stat               )
  trc_event( Event_dvm_exit             )
  trc_event( call_mps_Bcast             )
  trc_event( ret_mps_Bcast              )
  trc_event( call_mps_Barrier           )
  trc_event( ret_mps_Barrier            )
  trc_event( call_dvm_dfread            )
  trc_event( ret_dvm_dfread             )
  trc_event( call_dvm_dfwrite           )
  trc_event( ret_dvm_dfwrite            )
  trc_event( call_crtshg_               )
  trc_event( ret_crtshg_                )
  trc_event( call_inssh_                )
  trc_event( ret_inssh_                 )
  trc_event( call_strtsh_               )
  trc_event( ret_strtsh_                )
  trc_event( call_waitsh_               )
  trc_event( ret_waitsh_                )
  trc_event( call_delshg_               )
  trc_event( ret_delshg_                )
  trc_event( call_bbuf_Done             )
  trc_event( ret_bbuf_Done              )
  trc_event( call_bgroup_Done           )
  trc_event( ret_bgroup_Done            )
  trc_event( call_amview_Done           )
  trc_event( ret_amview_Done            )
  trc_event( call_ArrMap_Done           )
  trc_event( ret_ArrMap_Done            )
  trc_event( call_disarr_Done           )
  trc_event( ret_disarr_Done            )
  trc_event( call_RedGroup_Done         )
  trc_event( ret_RedGroup_Done          )
  trc_event( call_AMVMap_Done           )
  trc_event( ret_AMVMap_Done            )
  trc_event( call_getind_               )
  trc_event( ret_getind_                )
  trc_event( call_addhdr_               )
  trc_event( ret_addhdr_                )
  trc_event( call_delhdr_               )
  trc_event( ret_delhdr_                )
  trc_event( call_troff_                )
  trc_event( call_biof_                 )
  trc_event( ret_biof_                  )
  trc_event( call_eiof_                 )
  trc_event( ret_eiof_                  )
  trc_event( call_tsynch_               )
  trc_event( ret_tsynch_                )

  trc_event( call_getamr_               )
  trc_event( ret_getamr_                )
  trc_event( call_crtps_                )
  trc_event( ret_crtps_                 )
  trc_event( call_psview_               )
  trc_event( ret_psview_                )
  trc_event( call_delps_                )
  trc_event( ret_delps_                 )
  trc_event( call_setelw_               )
  trc_event( ret_setelw_                )
  trc_event( call_recvsh_               )
  trc_event( ret_recvsh_                )
  trc_event( call_sendsh_               )
  trc_event( ret_sendsh_                )
  trc_event( call_mapam_                )
  trc_event( ret_mapam_                 )
  trc_event( call_runam_                )
  trc_event( ret_runam_                 )
  trc_event( call_stopam_               )
  trc_event( ret_stopam_                )
  trc_event( call_arwelm_               )
  trc_event( ret_arwelm_                )
  trc_event( call_arwelf_               )
  trc_event( ret_arwelf_                )
  trc_event( call_acopel_               )
  trc_event( ret_acopel_                )
  trc_event( call_aelmcp_               )
  trc_event( ret_aelmcp_                )
  trc_event( call_aarrcp_               )
  trc_event( ret_aarrcp_                )
  trc_event( call_waitcp_               )
  trc_event( ret_waitcp_                )
  trc_event( call_crtrbl_               )
  trc_event( ret_crtrbl_                )
  trc_event( call_loadrb_               )
  trc_event( ret_loadrb_                )
  trc_event( call_waitrb_               )
  trc_event( ret_waitrb_                )
  trc_event( call_delrb_                )
  trc_event( ret_delrb_                 )
  trc_event( call_crtbg_                )
  trc_event( ret_crtbg_                 )
  trc_event( call_insrb_                )
  trc_event( ret_insrb_                 )
  trc_event( call_loadbg_               )
  trc_event( ret_loadbg_                )
  trc_event( call_waitbg_               )
  trc_event( ret_waitbg_                )
  trc_event( call_delbg_                )
  trc_event( ret_delbg_                 )

  trc_event( call_crtibl_               )
  trc_event( ret_crtibl_                )
  trc_event( call_loadib_               )
  trc_event( ret_loadib_                )
  trc_event( call_waitib_               )
  trc_event( ret_waitib_                )
  trc_event( call_delib_                )
  trc_event( ret_delib_                 )
  trc_event( call_crtig_                )
  trc_event( ret_crtig_                 )
  trc_event( call_insib_                )
  trc_event( ret_insib_                 )
  trc_event( call_loadig_               )
  trc_event( ret_loadig_                )
  trc_event( call_waitig_               )
  trc_event( ret_waitig_                )
  trc_event( call_delig_                )
  trc_event( ret_delig_                 )

  trc_event( call_DelDA                 )
  trc_event( ret_DelDA                  )

  trc_event( call_plmap_                )
  trc_event( ret_plmap_                 )

  trc_event( call_RegBufGroup_Done      )
  trc_event( ret_RegBufGroup_Done       )

  trc_event( call_crtrba_               )
  trc_event( ret_crtrba_                )
  trc_event( call_crtrbp_               )
  trc_event( ret_crtrbp_                )

  trc_event( call_genblk_               )
  trc_event( ret_genblk_                )

  trc_event( call_dyn_GetLocalBlock     )
  trc_event( ret_dyn_GetLocalBlock      )

  trc_event( call_rmkind_               )
  trc_event( ret_rmkind_                )

  trc_event( call_lindtp_               )
  trc_event( ret_lindtp_                )

  trc_event( call_setgrn_               )
  trc_event( ret_setgrn_                )
  trc_event( call_gettar_               )
  trc_event( ret_gettar_                )
  trc_event( call_rsttar_               )
  trc_event( ret_rsttar_                )

  trc_event( call_IdBufGroup_Done       )
  trc_event( ret_IdBufGroup_Done        )
  trc_event( call_StartLoadBuffer       )
  trc_event( ret_StartLoadBuffer        )
  trc_event( call_WaitLoadBuffer        )
  trc_event( ret_WaitLoadBuffer         )

  trc_event( call_crtib_                )
  trc_event( ret_crtib_                 )

  trc_event( call_acsend_               )
  trc_event( ret_acsend_                )
  trc_event( call_acrecv_               )
  trc_event( ret_acrecv_                )

  trc_event( call_recvla_               )
  trc_event( ret_recvla_                )
  trc_event( call_sendsa_               )
  trc_event( ret_sendsa_                )
  trc_event( call_across_               )
  trc_event( ret_across_                )

  trc_event( call_addbnd_               )
  trc_event( ret_addbnd_                )

  trc_event( call_incsh_                )
  trc_event( ret_incsh_                 )
  trc_event( call_incshd_               )
  trc_event( ret_incshd_                )

  trc_event( call_MPI_Allreduce         )
  trc_event( ret_MPI_Allreduce          )
  trc_event( call_MPI_Bcast             )
  trc_event( ret_MPI_Bcast              )
  trc_event( call_MPI_Barrier           )
  trc_event( ret_MPI_Barrier            )

  trc_event( call_dvm_gzsetparams       )
  trc_event( ret_dvm_gzsetparams        )
  trc_event( call_dvm_gzflush           )
  trc_event( ret_dvm_gzflush            )

  trc_event( call_doacr_                )
  trc_event( ret_doacr_                 )

  trc_event( call_rstshg_               )
  trc_event( ret_rstshg_                )

  trc_event( call_crtrda_               ) 
  trc_event( ret_crtrda_                ) 

  trc_event( call_strtac_               )
  trc_event( ret_strtac_                )
  trc_event( call_waitac_               )
  trc_event( ret_waitac_                )
  trc_event( call_crtcg_                )
  trc_event( ret_crtcg_                 )
  trc_event( call_inscg_                )
  trc_event( ret_inscg_                 )
  trc_event( call_strtcg_               )
  trc_event( ret_strtcg_                )
  trc_event( call_waitcg_               )
  trc_event( ret_waitcg_                )
  trc_event( call_delcg_                )
  trc_event( ret_delcg_                 )
  trc_event( call_DAConsistGroup_Done   )
  trc_event( ret_DAConsistGroup_Done    )
  trc_event( call_consda_               )
  trc_event( ret_consda_                )
  trc_event( call_inclcg_               )
  trc_event( ret_inclcg_                )
  trc_event( call_rstcg_                )
  trc_event( ret_rstcg_                 )
  trc_event( call_rstrda_               )
  trc_event( ret_rstrda_                )

  trc_event( call_rstbg_                )
  trc_event( ret_rstbg_                 )

  trc_event( call_addshd_               )
  trc_event( ret_addshd_                )

  trc_event( call_setba_                )
  trc_event( ret_setba_                 )
  trc_event( call_rstba_                )
  trc_event( ret_rstba_                 )

  trc_event( call_dvmcom_               )
  trc_event( ret_dvmcom_                )

  trc_event( call_exlsiz_               )
  trc_event( ret_exlsiz_                )
  trc_event( call_exlind_               )
  trc_event( ret_exlind_                )

  trc_event( call_blkdiv_               )
  trc_event( ret_blkdiv_                )

  trc_event( call_io_Sendnowait         )
  trc_event( ret_io_Sendnowait          )
  trc_event( call_io_Recvnowait         )
  trc_event( ret_io_Recvnowait          )
  trc_event( call_io_Waitrequest        )
  trc_event( ret_io_Waitrequest         )
  trc_event( call_io_Testrequest        )
  trc_event( ret_io_Testrequest         )

  trc_event( call_MPI_Alltoallv         )
  trc_event( ret_MPI_Alltoallv          )

  trc_event( call_dvmsend_              )
  trc_event( ret_dvmsend_               )
  trc_event( call_dvmrecv_              )
  trc_event( ret_dvmrecv_               )
  trc_event( call_dvmsendrecv_          )
  trc_event( ret_dvmsendrecv_           )
  trc_event( call_dvmreduce_            )
  trc_event( ret_dvmreduce_             )
  trc_event( call_dvmiprobe_            )
  trc_event( ret_dvmiprobe_             )

  trc_event( call_dvmsecread_           )
  trc_event( ret_dvmsecread_            )
  trc_event( call_dvmsecwait_           )
  trc_event( ret_dvmsecwait_            )
  trc_event( call_dvmsecwrite_          )
  trc_event( ret_dvmsecwrite_           )

  trc_event( call_pllind_               )
  trc_event( ret_pllind_                )

  trc_event( call_dacsum_               )
  trc_event( ret_dacsum_                )
  trc_event( call_getdas_               )
  trc_event( ret_getdas_                )
  trc_event( call_arcsum_               )
  trc_event( ret_arcsum_                )

  trc_event( call_dvmsync_              )
  trc_event( ret_dvmsync_               )

  trc_event( Event536                   )
  trc_event( Event537                   )
  trc_event( Event538                   )
  trc_event( Event539                   )
  trc_event( Event540                   )
  trc_event( Event541                   )
  trc_event( Event542                   )
  trc_event( Event543                   )
  trc_event( Event544                   )
  trc_event( Event545                   )
  trc_event( Event546                   )
  trc_event( Event547                   )
  trc_event( Event548                   )
  trc_event( Event549                   )

  /* Events of  dynamic control and user trace */    /*E0002*/

  trc_event( call_dprstv_               )
  trc_event( ret_dprstv_                )
  trc_event( call_dstv_                 )
  trc_event( ret_dstv_                  )
  trc_event( call_dldv_                 )
  trc_event( ret_dldv_                  )
  trc_event( call_dbegpl_               )
  trc_event( ret_dbegpl_                )
  trc_event( call_dbegsl_               )
  trc_event( ret_dbegsl_                )
  trc_event( call_dendl_                )
  trc_event( ret_dendl_                 )
  trc_event( call_diter_                )
  trc_event( ret_diter_                 )
  trc_event( call_drmbuf_               )
  trc_event( ret_drmbuf_                )
  trc_event( call_dskpbl_               )
  trc_event( ret_dskpbl_                )
  trc_event( call_dbegtr_               )
  trc_event( ret_dbegtr_                )
  trc_event( call_dread_                )
  trc_event( ret_dread_                 )
  trc_event( call_drarr_                )
  trc_event( ret_drarr_                 )
  trc_event( call_dcrtrg_               )
  trc_event( ret_dcrtrg_                )
  trc_event( call_dinsrd_               )
  trc_event( ret_dinsrd_                )
  trc_event( call_ddelrg_               )
  trc_event( ret_ddelrg_                )
  trc_event( call_dsavrg_               )
  trc_event( ret_dsavrg_                )
  trc_event( call_dclcrg_               )
  trc_event( ret_dclcrg_                )
  trc_event( Event584                   )
  trc_event( Event585                   )
  trc_event( Event586                   )
  trc_event( Event587                   )
  trc_event( Event588                   )
  trc_event( Event589                   )
  trc_event( Event590                   )
  trc_event( Event591                   )
  trc_event( Event592                   )
  trc_event( Event593                   )
  trc_event( Event594                   )
  trc_event( Event595                   )
  trc_event( Event596                   )
  trc_event( Event597                   )
  trc_event( Event598                   )
  trc_event( Event599                   )

  /* Statistics events */    /*E0003*/
                                      
  trc_event( call_binter_               )
  trc_event( ret_binter_                )
  trc_event( call_einter_               )
  trc_event( ret_einter_                )
  trc_event( call_bsloop_               )
  trc_event( ret_bsloop_                )
  trc_event( call_bploop_               )
  trc_event( ret_bploop_                )
  trc_event( call_enloop_               )
  trc_event( ret_enloop_                )
  trc_event( Event610                   )
  trc_event( Event611                   )
  trc_event( Event612                   )
  trc_event( Event613                   )
  trc_event( Event614                   )
  trc_event( Event615                   )
  trc_event( Event616                   )
  trc_event( Event617                   )
  trc_event( Event618                   )
  trc_event( Event619                   )
 
  return;
}

#endif   /*  _EVENTS_C_  */    /*E0004*/
