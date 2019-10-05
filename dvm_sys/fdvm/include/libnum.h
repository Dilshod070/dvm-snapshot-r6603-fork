enum {
      CLFDVM,     
      RTLINI,
      RTLEXI,
      GETAM,   
      GETVM,
      BEGBL,
      ENDBL,
      CRTAMV,
      DISAM,
      CRTDA,
      ALGNDA,
      REDVAR,
      REDVARF,
      CRTRG,
      INSRV,
      SAVERV,
      STARTR,
      WAITR,
      DELRG, 
      CRTSHG,
      DATOSHG,
      STARTSH,
      WAITSH,
      DELSHG,
      CRTPLP,
      BEGPLP,
      ENDPLP,
      BFIRST,
      BLAST,
      DOLOOP,
      GETADR,
      GETAI,
      GETAL,
      GETAF,
      GETAD,
      GETAC,
      GETACH,
      TSTIOP,
      GETRNK,
      GETSIZ,
      ARRCPY,
      SRMEM,
      RDISAM,
      REALGN,
      RWELM,
      RWELMF,
      DELOBJ,
      TSTELM,
      DLOADV,
      DSTORV,
      DPRSTV,
      DINOUT,
      DRMBUF,
      DITER,
      DBEGPL,
      DBEGSL,
      DENDL,
      DSKPBL,  
      BINTER,
      EINTER,
      BSLOOP,
      BPLOOP,
      ENLOOP,
      BIOF,
      EIOF,
      FNAME,
      LNUMB,
      ADDHDR,
      PSVIEW,
      CRTPS,
      GETAMV,
      GETAMR,
      MAPAM,
      RUNAM,
      STOPAM,
      CRTBG,
      LOADBG,
      WAITBG,
      CRTRB,
      CRTRBP,
      LOADRB,
      WAITRB,
      INSRB,  
      CRTIG,
      LOADIG,
      WAITIG,
      CRTIB,
      LOADIB,
      WAITIB,
      INSIB,
      INSSHD,
      SENDSH,
      RECVSH,
      TRON,
      TROFF,
      DBEGTR,
      GENBLI,
      TPCNTR,
      RMKIND,
      SETELW,
      DLOAD2,
      DREADA,
      DREAD,
      LINDTP,
      DVMRM,
      DVMSM,
      AARRCP,
      WAITCP,
      ACROSS,
      DVMLF,
      ADDBND,
      INCSH,
      INCSHD,
      DRARR,
      BARRIER,
      DINSRD,
      DCRRG,
      DSAVRG,
      DCLCRG,
      DDLRG,
      ADDSHD,
      CRTRDA,
      STRTAC,
      WAITAC,
      CRTCG,
      INSCG,
      STRTCG,
      WAITCG,
      DELCG,
      CONSDA,
      INCLCG,
      RSTRDA,
      RSTCG, 
      CRTRA9,
      CRTDA9,
      FTCNTR,
      DACSUM,
      ARCSF,
      BLKDIV,
      DOPLMB,
      DOSL,
      DVTR,
      DOPLSEQ,
      INIMPI,
      DVMH_INIT,
      DVMH_FINISH,
      INIT_CUDA,
      REG_CREATE,
      REG_END,
      REG_DEVICES,
      REG_START,
      RGSTR_ARRAY_2,
      RGSTR_SUBARRAY_2,
      RGSTR_SCALAR_2,
      RGSTR_ARRAY,
      RGSTR_SUBARRAY,
      RGSTR_SCALAR,
      SET_NAME_ARRAY,
      SET_NAME_VAR,
      BEFORE_LOADRB,
      REG_WAITRB,
      REG_DESTROY_RB,
      GET_ACTUAL_EDGES,
      SHADOW_RENEW,
      SHADOW_RENEW_2,
      INDIRECT_SH_RENEW,
      LOOP_CREATE,
      LOOP_CREATE_2,
      REG_HANDLER,
      REG_HANDLER_2,
      HANDLER_FUNC,
      LOOP_START,
      LOOP_END,
      LOOP_PERFORM,
      LOOP_PERFORM_2,
      CUDA_BLOCK,
      CUDA_BLOCK_2,
      LOOP_INSRED,
      LOOP_RED,
      SHADOW_COMPUTE,
      SHADOW_COMPUTE_AR,
      SHADOW_COMPUTE_2,
      GET_ACTUAL_ALL,
      GET_ACTUAL_ALL_2,
      GET_ACTUAL_ARRAY,
      GET_ACTUAL_ARR_2,
      GET_ACTUAL_SUBARRAY,
      GET_ACTUAL_SUBARR_2,
      GET_ACTUAL_SCALAR,
      GET_ACTUAL_SCALAR_2,
      GET_ACTUAL_SUBVAR,
      GET_ACTUAL_SUBVAR_2,
      ACTUAL_ARRAY,
      ACTUAL_ARRAY_2,
      ACTUAL_SUBARRAY,
      ACTUAL_SUBARRAY_2,
      ACTUAL_SCALAR,
      ACTUAL_SCALAR_2,
      ACTUAL_SUBVAR,
      ACTUAL_SUBVAR_2,
      ACTUAL_ALL,
      ACTUAL_ALL_2,
      DVMH_REDISTRIBUTE,
      DVMH_REALIGN,
      DESTROY_ARRAY,
      DESTROY_SCALAR,
      HANDLE_CONSIST,
      LOOP_ACROSS,
      LOOP_ACROSS_2,
      GET_STAGE,
      MAP_TASKS,
      DATA_ENTER,
      DATA_EXIT,
      DELETE_OBJECT,
      FORGET_HEADER,
      SCOPE_START, 
      SCOPE_END,
      SCOPE_INSERT, 
      LOOP_MAP,
      ALIGN_LINEAR,
      REGISTER_ARR,
      GET_ADDR,
      STRING,
      STRING_VAR,
      VAR_GEN_HDR,
      VAR_FILL_HDR,
      DVMH_LINE,
      CREATE_ARRAY, 
      CREATE_TEMPLATE,
      DVMH_REPLICATED, 
      DVMH_BLOCK,      
      DVMH_WGTBLOCK,  
      DVMH_GENBLOCK,   
      DVMH_MULTBLOCK,
      DVMH_INDIRECT,
      DVMH_DERIVED,  
      DVMH_DISTRIBUTE,
      DVMH_REDISTR_2, 
      DVMH_ALIGN,
      DVMH_REALIGN_2,
      DVMH_HAS_ELEMENT,
      CALC_LINEAR,
      LOCALIZE,      
      SHADOW_ADD,
      EXPR_IGNORE,
      EXPR_CONSTANT,
      EXPR_SCAN,
      DERIVED_RHS,
      ARRAY_SLICE,
      COPY_WHOLE,
      COPY_ARRAY,
      FTN_OPEN,
      FTN_CLOSE,
      FTN_READ,
      FTN_WRITE,
      FTN_ENDFILE,
      FTN_FLUSH,
      FTN_REWIND,
      FTN_CONNECTED,      
      FILL_BOUNDS,
      RED_INIT,
      RED_POST,
      SLOT_COUNT,
      HAS_ELEMENT,
      HAS_ELEMENT_2,
      FILL_LOCAL_PART,
      OMP_STAT_BP,
      OMP_STAT_AP,
      OMP_STAT_BL,
      OMP_STAT_AL,
      OMP_STAT_BS,
      OMP_STAT_AS,      
      GET_BASE,
      GET_BASE_C,
      FILL_HEADER,
      FILL_HEADER_2,
      FILL_HEADER_EX,
      FILL_HEADER_EX_2,
      DO_CUDA,
      RED_CUDA,
      RED_CUDA_C,
      REGISTER_RED,
      RED_INIT_C,
      RED_INIT_2,
      CUDA_RED_INIT,
      CUDA_RED_INIT_2,
      RED_PREPARE,
      RED_PREPARE_C,
      RED_FINISH,
      RED_FINISH_C,
      SHARED_NEEDED,
      GET_DEVICE_ADDR,
      GET_DEVICE_ADDR_C,
      GET_LOCAL_PART,
      GET_LOCAL_PART_C,
      GET_DEVICE_NUM,
      GET_DEVICE_NUM_2,
      GET_OVERALL_STEP,
      FILL_BOUNDS_C,
      FILL_BOUNDS_2,
      RED_POST_C,
      RED_POST_2,
      CUDA_REPLICATE, 
      GET_DEP_MASK,
      GET_DEP_MASK_2,
      GET_DEP_MASK_F,
      CUDA_TRANSFORM,
      CUDA_AUTOTRANSFORM,
      LOOP_AUTOTRANSFORM,
      APPLY_OFFSET,
      GET_CONFIG,
      GET_CONFIG_C,
      CHANGE_BOUNDS,
      GUESS_INDEX_TYPE,
      GUESS_INDEX_TYPE_2,
      RTC_SET_LANG,
      MAX_LIBFUN_NUM
};  
