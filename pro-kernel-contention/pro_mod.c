#include<linux/module.h>
#include<linux/sched.h>
#include<linux/kernel.h> 
#include<linux/init.h> 
#include<linux/unistd.h>
#include<linux/mm.h>
#include<linux/delay.h>
#include<linux/slab.h>

//Extern Declarations
extern int pro_mod_set, pro_mod_dset, pro_pid_set, pro_pid_dset;
int pid_tmp,timeX;

// Module paramaters
module_param(pid_tmp, int, 0);
module_param(timeX, int, 0);

int init_module(void){
	pro_mod_set=0; 	
	pro_mod_dset=0;
	
	if(!pro_mod_set){
		pro_pid_set=pid_tmp;
		pro_pid_dset=pid_tmp;

		pro_mod_set=1;
		pro_mod_dset=1;
	}
	
	msleep(timeX*1000);

	pro_mod_set=0;
	pro_mod_dset=0;

	return 0;
}

void cleanup_moudle(void){	
	pro_mod_set=0;
	pro_mod_dset=0;
}

MODULE_LICENSE("GPL");
