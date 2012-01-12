/*
 * =====================================================================================
 *
 *       Filename:  pthread_test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/24/2011 04:39:20 PM
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
#include <sys/types.h>
pthread_t ntid;

void print_ids(const char*s)
{
 pid_t pid;
 pthread_t tid;
 
 pid=getpid();
 tid = pthread_self();
 printf("%s pid %u tid %u (0X%x)\n",s,(unsigned int )pid,(unsigned int)tid,(unsigned int)tid);

}

void* thread_func(void *argv)
{
	print_ids("new thread:");
	
	for(int i=0;i<10;i++)
        {
 	  printf("$ sleep 3s.. loop=%d\n",i);
	  sleep(3);
	}	
	return ((void*)0);
}
int main(int argc,char**argv)
{
	int error;
	error=pthread_create(&ntid,NULL,thread_func,NULL);
	if(error!=0)
	{
 		printf(" pthread creat error \n");
	}
	print_ids("main thread:");
	for(int i=0;i<10;i++)
        {
 	  printf("# sleep 3s.. loop=%d\n",i);
	  sleep(10);
	}	
}
