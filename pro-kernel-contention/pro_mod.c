#include<linux/module.h>
#include<linux/sched.h>
#include<linux/kernel.h> 
#include<linux/init.h> 
#include<linux/unistd.h>
#include<linux/mm.h>
#include<linux/delay.h>
#include<linux/slab.h>

#define MAX_CPU 4
//Extern Declarations
extern int pro_mod_set, pro_mod_fset, pro_pid_set, pro_pid_fset, *pro_fread, *pro_fwrite, pro_read, *pro_ins, *pro_del;
int pid_tmp,timeX,typex, tGap=30, nDur=0;

// Module paramaters
module_param(pid_tmp, int, 0);
module_param(timeX, int, 0);
module_param(typex, int, 0);	//type: 2-fs 1-t_group

int init_module(void){
	pro_mod_set=0; 	
	pro_mod_fset=0;
	int i,pro_w=0,pro_r=0;
	
	if(!pro_mod_set && typex==1){
		pro_pid_set=pid_tmp;
		pro_read=0;

		pro_ins=(int*)kmalloc(20*sizeof(int), GFP_KERNEL);
		pro_del=(int*)kmalloc(20*sizeof(int), GFP_KERNEL);

		for(i=0;i<20;i++){
			pro_ins[i]=0;
			pro_del[i]=0;
		}		

		pro_mod_set=1;
	}
	else if(!pro_mod_fset && typex==2){
		pro_pid_fset=pid_tmp;
		
		pro_fwrite=(int*)kmalloc(20*sizeof(int), GFP_KERNEL);
		pro_fread=(int*)kmalloc(20*sizeof(int), GFP_KERNEL);

		for(i=0;i<20;i++){
			pro_fread[i]=0;
			pro_fwrite[i]=0;
		}

		pro_mod_fset=1;
	}

	while(nDur<timeX){
		if(typex==1){
			for(i=0;i<MAX_CPU;i++) pro_w+=pro_ins[i]+pro_del[i];
			printk("[promod %d] IRCU: S%ld E%ld K%ld\n", pid_tmp, pro_read, pro_w, 1);
		}
		else{
			for(i=0;i<MAX_CPU;i++){
				pro_w+=pro_fwrite[i];
				pro_r+=pro_fread[i];
			}

			printk("[promod %d] IRCU: S%ld E%ld K%ld\n", pid_tmp, pro_read, pro_w, 1);
		}
		msleep(tGap*1000);
		nDur+=tGap;
	}

	pro_mod_set=0;
	pro_mod_fset=0;

	return 0;
}

void cleanup_moudle(void){	
	pro_mod_set=0;
	pro_mod_fset=0;
}

MODULE_LICENSE("GPL");
