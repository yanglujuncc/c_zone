/*
 * =====================================================================================
 *
 *       Filename:  worker_server.c
 *
 *    Description:  ylj
 *
 *        Version:  1.0
 *        Created:  07/14/2011 02:41:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>


#include "worker_server.h"
//#include "package.h"

#include "services_list.h"
//#include "helloword_service.h"

/*  
void runservices(int32_t client_fd)
{
  const int32_t BUFFERSIZE=200;
  char* buffer=(char*)malloc(BUFFERSIZE);
  
  int32_t recvbytes=0;
  int32_t data_recvbytes = 0;
  int32_t loop_recvbytes=0;

  int32_t package_head_size= sizeof(struct package_head);
  struct package_head *_package_head;
  
  while(1)
  {
    	loop_recvbytes=recv(client_fd, buffer+recvbytes, BUFFERSIZE, 0);
        recvbytes += loop_recvbytes; 
   
	if(recvbytes<package_head_size)
    	{	
		continue;
    	}
	_package_head=(struct package_head *)buffer;
	
	if(check_package_head(_package_head)!=PACKAGE_HEAD_OK)
	{
		//error
		close(client_fd);
		return;
	}
	
	data_recvbytes = recvbytes-package_head_size;
	if(data_recvbytes<_package_head->data_length)
	{
		continue;
	}		
	
	char* return_data=NULL;
	int32_t return_data_count=0;		
	do_service(_package_head,&return_data,&return_data_count);
	close(client_fd);
       return;	
  }		
}

int32_t do_service(struct package_head *_package,char** return_data_ptr,int32_t *return_data_count)
{
	if(_package==NULL)
	{
		*return_data_ptr=NULL;
		*return_data_count=0;
		return ;
	}
	
	int32_t _service_kind=_package->call_service_ID;
	char* input_data = (char* )_package+sizeof(struct package_head);
	int32_t input_data_length = _package->data_length;
	
	
	switch(_service_kind)
	{
		case SERVICE_HELLOWORD:
			helloword_service(NULL, 0,return_data_ptr,return_data_count);
			return 0;
				
	}
}
*/
int main (int argc,char** argv)
{
	struct worker_server  _server;
        struct sockaddr_in remote_addr;

        _server.listen_socket_fd=-1;
        _server.addr_in.sin_family=AF_INET;
        _server.addr_in.sin_port=htons(PORT_WORKER);
        _server.addr_in.sin_addr.s_addr = INADDR_ANY;

        _server.services_count=1;


	if((_server.listen_socket_fd=socket(AF_INET,SOCK_STREAM,0))==-1)
        {
                printf("soket creat failed\n");
                return -1;
        }
	
	 if(bind(_server.listen_socket_fd,(struct sockaddr*)&_server.addr_in,sizeof(struct sockaddr))==-1)
        {
                printf("bind failed\n");
                return -1;
        }
    
	if(listen(_server.listen_socket_fd,1000)==-1)
        {
                perror("listen failed");
                return -1;
        }

	 while(1)
        {
                int sin_size;
                int client_fd;
               // char ip_addr[20]={0};
                printf("wating for connetion\n");

                if((client_fd = accept(_server.listen_socket_fd,(struct sockaddr*)&remote_addr,(void*)&sin_size))==-1)
                {
                        perror("accept error");
                        continue;
                }
                printf("received a connection  \n");
	//	runservices(client_fd);

        }

	return 0;
}







