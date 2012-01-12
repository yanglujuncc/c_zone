/*
 * =====================================================================================
 *
 *       Filename:  master.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/14/2011 11:48:02 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
*/

#ifndef _MASTER_CILENT_H 
#define _MASTER_CLIENT_H 

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "worker_client.h"


#define  IP_MASTER  "10.20.146.85"
#define PORT_MASTER  5555

struct master_client
{
 struct sockaddr_in addr_in;
 int32_t connection_fd;

 struct worker *worker_joined;
 int32_t worker_count;

}
;
int32_t connect_to_master(struct master_client* _master);
int32_t isconnet_master(struct master_client* _master);
int32_t close_connect_master(struct master_client* _master);
//int32_t get_workers_of_service(struct master* _master,int32_t service_kind,struct worker ** worker_arrary,int32_t* arrary_count);


#endif
