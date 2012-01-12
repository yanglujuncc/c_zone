/*
 * =====================================================================================
 *
 *       Filename:  Pthread.c
 *
 *    Description:  yy
 *
 *        Version:  1.0
 *        Created:  08/08/2011 05:10:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */



#include <stdio.h>
#include <pthread.h>

int go=2;

typedef struct share_data_s{
 
	int data;
	pthread_mutex_t lock_t;
	

}share_data_t;


share_data_t share_data;

void init()
{
	share_data.data=0;
	pthread_mutex_init(share_data.lock_t);

}


void change_data()
{

	
	if(thread_mutex_trylock())
	{
		printf("wait for the lock...pthred:%d\n",pthread_self());
		pthread_mutex_lock( share_data.lock_t);	
	}
	//pthread_mutex_trylock();
	//
	printf("get the lock...pthred:%d\n",pthread_self());
	sharedata.data++;
	printf("release the lock...pthred:%d\n",pthread_self());
	
	pthread_mutex_unlock(share_data.lock_t);	
	
	//pthread_mutex_trylockharedata.lock_t);

}
void *thread_run(void *arg)
{
	printf("thread_id=%u\n",(unsigned int)pthread_self());
        printf("thread 1 running \n");
      
	change_data();	 
	pthread_exit(&go);

}


int main(int argc,char**argv)
{
        int err;
        pthread_t tids[2];
        void *tret;
	
	init();
	
	for(int i=0;i<2;i++)
	{
       		err=pthread_create(&tids[i],NULL,thread_run,NULL);
        	if(err!=0)
               		 printf("pthread_create failed\n");
        	printf("pthread_create sucess\n");
	}
	
	for(int i=0;i<2;i++)
	{
		
        	err=pthread_join(&tids[i],&tret);
        	if(err!=0)
                	printf("join failed\n");
        	printf("join success return %d\n",*(int *)tret);
	
	}	
	
        return 0;
}
