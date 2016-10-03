#ifndef PROMOD_BEGIN

#define PROMOD_BEGIN 			\
	uint64_t ts0=0, ts1=0; 		\
   	uint32_t cX_1=0,cX_2=0;		\
  	long long tmp_1;			

#define PROMOD_TS0				\
	ts0 = rdtscp(&cX_1); 

#define PROMOD_TS1			\
	ts1 = rdtscp(&cX_2);	\
	tmp_1=ts1-ts0; 

#define PROMOD_END(DS_ID)											\
		printk("[profmod %s] PRCU: S%u E%u K%lld\n", DS_ID, cX_1, cX_2, tmp_1);	// [pro mod]	
			
#define PROMOD_READ(DS_ID)											\
		printk("[profmod %s] RRCU: S%u E%u K%lld\n", DS_ID, cX_1, cX_2, 1);	// [pro mod]	

#define PROMOD_WRITE(DS_ID)											\
		printk("[profmod %s] WRCU: S%u E%u K%lld\n", DS_ID, cX_1, cX_2, 1);	// [pro mod]

#endif		


