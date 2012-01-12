/*
 * =====================================================================================
 *
 *       Filename:  master_server.c
 *
 *    Description:  ylj
 *
 *        Version:  1.0
 *        Created:  07/14/2011 01:08:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>

#include "master_server.h"


int32_t main(int32_t argc,char** argv)
{
	struct master_server  _server;
	struct sockaddr_in remote_addr;

	_server.listen_socket_fd=-1;
        _server.addr_in.sin_family=AF_INET;
        _server.addr_in.sin_port=htons(PORT_MASTER);
        _server.addr_in.sin_addr.s_addr = INADDR_ANY;
	
	_server.worker_count=-1;

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
                //char ip_addr[20]={0};
                printf("wating for connetion\n");
                
		if((client_fd = accept(_server.listen_socket_fd,(struct sockaddr*)&remote_addr,(void*)&sin_size))==-1)
                {
                        perror("accept error");
                        continue;
                }
                printf("received a connection from \n");

	}

	return 0;
}
