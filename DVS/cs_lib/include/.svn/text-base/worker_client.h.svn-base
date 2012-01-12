/*
 * =====================================================================================
 *
 *       Filename:  worker_client.h
 *
 *    Description:  ylj
 *
 *        Version:  1.0
 *        Created:  07/14/2011 11:19:37 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef _WORKER_CLIENT_H 
#define _WORKER_CLIENT_H

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define  IP_WORKER  "10.20.146.85"
#define  PORT_WORKER  5556

struct worker_client
{
 struct sockaddr_in addr_in;
 int32_t connection_fd;

 int32_t *service_arrary;
 int32_t service_count;
    
	
};

int32_t connect_to_worker(struct worker_client* _worker);

int32_t isconnet_worker(struct worker_client* _worker);

int32_t close_connect_worker(struct worker_client* _worker);

int32_t get_worker_services(struct worker_client* _worker,int32_t** services_arrary,int32_t* arrary_count);

int32_t invoke_worker(struct worker_client* _worker,int32_t serviceID,char* input_data,int32_t input_length,char** output_data_ptr,int32_t *output_length);


#endif
