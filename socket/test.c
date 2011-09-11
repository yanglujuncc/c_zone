#include<stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>

#include <sys/time.h>

#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SERVPORT 4444
#define MAXDATASIZE 100 /*每次最大数据传输量 */
#define BACKLOG 10
int main(int argc, char *argv[])
{	
	int sockfd;
	fd_set rset;
	struct timeval time;
	struct sockaddr_in my_addr;
	time.tv_sec=2;
	time.tv_usec=0;
	
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
        {
                perror("socket creat error!");
                exit(1);
        }
        
        printf("sockfd = %d\n",sockfd);
        my_addr.sin_family=AF_INET;
        my_addr.sin_port=htons(SERVPORT);
        my_addr.sin_addr.s_addr=INADDR_ANY;
        bzero(&(my_addr.sin_zero),8);

        if(bind(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr))==-1)
        {
                perror("bind error!");
                exit(1);
        }
        if(listen(sockfd,BACKLOG)==-1)
        {
                perror("listen error!");
                exit(1);
        }


	FD_ZERO(&rset);
	FD_SET(sockfd,&rset);
	printf(" FD_ISSET(sockfd,&rset) = %d\n",FD_ISSET(sockfd,&rset));
	
	printf(" select ...\n");
	select(sockfd+1,&rset,NULL,NULL,&time);
	printf(" after  select ...\n");
	
	printf(" FD_ISSET(sockfd,&rset) = %d\n",FD_ISSET(sockfd,&rset));
	
	//printf("FD_SETSIZE = %d \n",FD_SETSIZE );
	return 0;
}
