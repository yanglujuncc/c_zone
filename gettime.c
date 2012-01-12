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
	

	time(&now);
	
	printf("ctime = %s",ctime(&now));

	struct tm *t;
			
	t=localtime(&now);
	char arrary[100];
	strftime(arrary,100,"%F %T",t);
	printf("strtime=%s\n",arrary);
	if(now>0)
	{
		printf("hello,word");
		printf("hello,word");
		printf("hello,word");
		printf("hello,word");
	}
	else
	{
		
		printf("hello,word");
		printf("hello,word");
	}
	return 0;
}

