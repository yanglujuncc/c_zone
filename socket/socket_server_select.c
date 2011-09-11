#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <sys/time.h>
#include <sys/select.h>

#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define SERVPORT 4444
#define BACKLOG 10
#define BUFF_SIZE 100

int main(int argc,char** argv)
{
	int sockfd,client_fd;
	struct sockaddr_in my_addr;
	struct sockaddr_in remote_addr;
	
	int clients[10]={-1};
	int client_num=0;
	char buff[BUFF_SIZE];
	char sbuff[BUFF_SIZE];
	int sbuff_len;
	fd_set rset;
	char zero_c='0';
	int nready=0;	
	struct timeval  wtime;
	
	wtime.tv_sec=2;
	wtime.tv_usec=0;
	
	strcpy(sbuff,"come a new client = 0 !");
	sbuff_len = strlen(sbuff);

	printf("sbuff(%d) = %s\n",sbuff_len,sbuff);
	FD_ZERO(&rset);
		
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
				
		printf("setting fd...\n");
		FD_ZERO(&rset);
		FD_SET(sockfd,&rset);
		for(int j=0;j<client_num;j++)
		{
			if(clients[j]>0)
			{
				FD_SET(clients[j],&rset);
			}
		}
		wtime.tv_sec=9;
		wtime.tv_usec=0;
	
		printf("select...\n");
		
		nready=select(10,&rset,NULL,NULL,&wtime);
		
		printf("nready = %d\n",nready);	
		
		if(FD_ISSET(sockfd,&rset))
		{
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
			//send info to other clients;
			for(int i=0;i<client_num;i++)
			{
				if(clients[i]<0)
				{
					break;
				}
				sbuff[20]=client_fd+zero_c;
			    	send(clients[i],sbuff,strlen(sbuff)+1,0);
			}
			clients[client_num++]=client_fd;
			
			
		}
		
		for(int i=0;i<client_num;i++)
		{
			if(clients[i]<0)
			{
				break;
			}
		
			if(FD_ISSET(clients[i],&rset))
			{
				
			    int recv_cnt=recv(clients[i],buff,BUFF_SIZE,0);
			    printf("recv_cnt=%d,recv:%s\n",recv_cnt,buff);
			}
		}	
	}		
	return 0;


}

