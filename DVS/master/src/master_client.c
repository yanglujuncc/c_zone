/*
 * =====================================================================================
 *
 *       Filename:  master_client.c
 *
 *    Description:  ylj
 *
 *        Version:  1.0
 *        Created:  07/14/2011 12:42:23 PM
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

#include "master_client.h"

int32_t connect_to_master ( struct master_client*  _master)
{
 	if((_master->connection_fd=socket(AF_INET,SOCK_STREAM,0))==-1)
        {
                printf("socket create failed\n");
                return -1;
        }
 
	if(connect(_master->connection_fd,(struct sockaddr*)&_master->addr_in,sizeof(struct sockaddr))==-1)
        {
                printf("connect error\n");
                return -1;
        }
	printf("connect success!\n ");

	return 0;
}


int32_t isconnet_master(struct master_client*_master)
{
	if(_master->connection_fd>0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int32_t close_connect_master(struct master_client* _master)
{
	if(_master->connection_fd>0)
	{
		close(_master->connection_fd);
		return 0;
	}
	else
		return -1;
}
/*  
int32_t get_workers_of_service(struct master*,int32_t service_kind,struct worker ** worker_arrary,int32_t* arrary_count)
{
	return 0;
}
*/
