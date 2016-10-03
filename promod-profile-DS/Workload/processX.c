//Start multiple threads[synthetic workload]!

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>

pthread_t t_id[2000]={0};
int n_thread;

void* run_thread(void *arg){
	sleep(2);
}

int main(int argc,char **argv){	
	int i;	
	n_thread=atoi(argv[1]);		// number of threads
	// Create Threads
	for(i=0;i<n_thread;i++)
		pthread_create(&t_id[i],NULL,&run_thread,NULL);
	
	sleep(2);	// Allow threads to start

	for(i=0;i<n_thread;i++)
		pthread_join(t_id[i],NULL);
	return 0;
}	
