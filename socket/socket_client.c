#include<stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SERVPORT 4444
#define MAXDATASIZE 100 

int main(int argc, char *argv[]){
	int sockfd, recvbytes;
	int sendbytes=0;
	char  buf[MAXDATASIZE];
	char sbuff[MAXDATASIZE];
	struct hostent *host;
	struct sockaddr_in serv_addr;
	
	
	strcpy(sbuff,"echo...");
	
	if (argc < 2)
	{
		fprintf(stderr,"Please enter the server's hostname!\n");
		exit(1);
	}
	if((host=gethostbyname(argv[1]))==NULL)
	{
		herror("gethostbyname出错！");
		exit(1);
	}
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket创建出错！");
		exit(1);
	}
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(SERVPORT);
	serv_addr.sin_addr = *((struct in_addr *)host->h_addr);
	bzero(&(serv_addr.sin_zero),8);
	
	if (connect(sockfd, (struct sockaddr *)&serv_addr,sizeof(struct sockaddr)) == -1) 
  	{
		perror("connect出错！");
		exit(1);
	}
	//five read functions
	
	//#first  read()
	char zero='0';
	while(1)
	{
		if ((recvbytes=read(sockfd, buf, MAXDATASIZE)) ==-1)
		{
			perror("read 出错！");
			exit(1);
		}
		else
		{
			printf("recvbytes=%d ,recv:%s\n",recvbytes,buf);	
		}
			
		sbuff[8]=zero++;
		sbuff[9]='\0';
		if( send(sockfd,sbuff,strlen(sbuff)+1,0)==-1)
		{
			printf("send error !");
			exit(1);
		} 
	}
	//#second  <sys/uio.h>
	//ssize_t readv(int fd ,const struct iovec *iov,int iovcnt)
	//struct iovec{
	//	void* iov_base;
	//	size_t iov_len;
	//	}
	//可以将读取结果写入多个缓存区
	/*
	if ((recvbytes=readv(sockfd, buf, MAXDATASIZE, 0)) ==-1)
	{
		perror("readv 出错！");
		exit(1);
	}
	*/
	//#third  <sys/socket.h>
	//ssize_t recv(int sockfd,void*buff,size_t nbytes,int flags);
	//flags = MSG_DONTROUTE,MSG_DONTWAIT,MSG_OOB,MSG_PEEK,MSG_WAITALL;
	//
	//
	/*
	if ((recvbytes=recv(sockfd, buf, MAXDATASIZE, 0)) ==-1)
	{
		perror("recv出错！");
		exit(1);
	}
	*/

	//#fourth 
	//ssize_t recvfrom(int sockfd,void* buff,size_t nbytes,int flags,
	//			struct sockaddr *from,socklen_t *addrlen);
	//
	/*
	if ((recvbytes=recvfrom(sockfd, buf, MAXDATASIZE, 0,&clientaddr,&addrlen)) ==-1)
	{
		perror("recvfrom 出错！");
		exit(1);
	}
	*/

	//#fifth 
	//ssize_t recvmsg(int sockfd,struct msghadr*msg,int flags)
	//struct msghdr{
	//	void*	msgname;
	//	socklen_t msg_namelen;
	//	strcut iovec *msg_iov; //iovec arrary
	//	int msg_iovlen;		//elements in msg_iov
	//	void*	msg_control;	
	//	socklen_t msg_controllen;
	//	int msg_flags;
	// }
	//功能最全面
	/*
	if ((recvbytes=recvmsg(sockfd, buf, MAXDATASIZE, 0)) ==-1)
	{
		perror("recvmsg 出错！");
		exit(1);
	}
	*/
	close(sockfd);
	return 0;
}
