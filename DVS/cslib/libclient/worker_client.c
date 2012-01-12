/*
 * =====================================================================================
 *
 *       Filename:  worker_client.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/14/2011 02:28:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include "worker_client.h"
#include <unistd.h>

int32_t connect_to_worker(struct worker_client* _worker_client)
{
	if((_worker_client->connection_fd=socket(AF_INET,SOCK_STREAM,0))==-1)
        {                         
                printf("socket create failed\n");
                return -1;        
        }                         
                                  
        if(connect(_worker_client->connection_fd,(struct sockaddr*)&_worker_client->addr_in,sizeof(struct sockaddr))==-1)
        {                         
                printf("connect error\n");
                return -1;
        }
        printf("connect success!\n ");

        return 0;
}                                   
int32_t isconnet_worker(struct worker_client* _worker_client)
{
 	if(_worker_client->connection_fd>0)
        {                     
                return 0;
        }
        else
        {
                return -1;
        }
}
                                 
int32_t close_connect_worker(struct worker_client* _worker_client)
{

        if(_worker_client->connection_fd>0)
        {
                close(_worker_client->connection_fd);
                return 0;
        }
        else
                return -1;
}

int32_t get_worker_services(struct worker_client* _worker,int32_t** services_arrary,int32_t* arrary_count)
{
	return -1;
}
                            
int32_t invoke_worker(struct worker_client* _worker,int32_t serviceID,char* input_data,int32_t input_length,char** output_data_ptr,int32_t *output_length)
{
	return 0;	
}
