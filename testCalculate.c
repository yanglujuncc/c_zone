#include <stdio.h>
#include <sys/time.h>

int main(int argc,char** argv)
{
	long i=1;
	long ii=2;
	struct timeval tv_begin;
	struct timeval tv_end;
	long loop=1000000000L;
	gettimeofday(&tv_begin,NULL);
	//long time_begin=time(0);	
	for(long j=0;j<loop;j++)
	{
		i=ii+i;
	//	ii=i+ii;
	}
	//long time_end=time(0);	
	
	gettimeofday(&tv_end,NULL);

	
	printf("i=%ld\n",i);
	printf("ii=%ld\n",ii);
	//printf("time_begin=%ld\n",time_begin);
	//printf("time_end=%ld\n",time_end);
	printf("begin: tv_sec=%lds,tv_usec=%ldus\n",tv_begin.tv_sec,tv_begin.tv_usec);
	printf("end  :tv_sec=%lds,tv_usec=%ldus\n",tv_end.tv_sec,tv_end.tv_usec);

	//printf("time_=%ldms\n",time_end-time_begin);
	printf("time_sec=%lds,time_usec=%ldus\n",tv_end.tv_sec-tv_begin.tv_sec,tv_end.tv_usec-tv_begin.tv_usec);
	printf("usec=%ldus\n",(tv_end.tv_sec-tv_begin.tv_sec)*1000000+tv_end.tv_usec-tv_begin.tv_usec);
	double msec=(tv_end.tv_sec-tv_begin.tv_sec)*1000+(tv_end.tv_usec-tv_begin.tv_usec)/1000;
	double usec=(tv_end.tv_sec-tv_begin.tv_sec)*1000000+(tv_end.tv_usec-tv_begin.tv_usec);
	
	printf("usec=%ldms\n",(tv_end.tv_sec-tv_begin.tv_sec)*1000+(tv_end.tv_usec-tv_begin.tv_usec)/1000);
	printf("%lfloops/ms\n",loop/msec);
	printf("%lfloops/us\n",loop/usec);
	
	return 0;
	

}
