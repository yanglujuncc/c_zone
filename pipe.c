#include <unistd.h>
#include <stdio.h>


int main()
{
 int pipe_fd[2];

 if( pipe(pipe_fd)<0){
	printf("pipe failed\n");
    return -1;
 }
 else
 {
   printf("pipe_fd[0]=%d,pipe_fd[1]=%d\n",pipe_fd[0],pipe_fd[1]);
 }
 return 0;
if()

}

