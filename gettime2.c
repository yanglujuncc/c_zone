/*
 * =====================================================================================
 *
 *       Filename:  gettime.c
 *
 *    Description:  ylj
 *
 *        Version:  1.0
 *        Created:  08/17/2011 01:36:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <time.h>

int main(int argc ,char** argv)
{
	time_t now;
	struct timespec time1 = {0, 0};
	clock_gettime(CLOCK_REALTIME, &time1);
	printf("CLOCK_REALTIME: %d, %d", time1.tv_sec, time1.tv_nsec);

	clock_gettime(CLOCK_MONOTONIC, &time1);
	printf("CLOCK_MONOTONIC: %d, %d", time1.tv_sec, time1.tv_nsec);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	printf("CLOCK_PROCESS_CPUTIME_ID: %d, %d", time1.tv_sec, time1.tv_nsec);
	clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time1);
	printf("CLOCK_THREAD_CPUTIME_ID: %d, %d", time1.tv_sec, time1.tv_nsec);
	//sys_clock_gettime 
	time(&now);

	printf("ctime = %s",ctime(&now));

	struct tm *t;

	t=localtime(&now);
	char arrary[100];
	strftime(arrary,100,"%F %T",t);
	printf("strtime=%s\n",arrary);
	return 0;	
	return 0;
}
