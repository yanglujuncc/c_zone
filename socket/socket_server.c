#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define SERVPORT 4444
#define BACKLOG 10

int main(int argc,char** argv)
{
	int sockfd,client_fd;
	struct sockaddr_in my_addr;
	struct sockaddr_in remote_addr;
		
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket creat error!");
		exit(1);
	}
	printf("sockfd = %d\n",sockfd);
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

	while(1)
	{
		printf("wating connection...\n");
		int s_addr_in_size=sizeof(struct sockaddr_in);

		if((client_fd=accept(sockfd,(struct sockaddr*)&remote_addr,&s_addr_in_size))==-1)
		{
			perror("accpet error!");	
			continue;
		}
		
		printf("received a connection from %s\n",inet_ntoa(remote_addr.sin_addr));
		printf("client_fd =  %d\n",client_fd);
		
		if(send(client_fd,"Hello, you are connected!\n", 26, 0) == -1)
		{
			perror("send error!");
			close(client_fd);
			exit(0);
		}
		close(client_fd);
	}
	return 0;


}	
