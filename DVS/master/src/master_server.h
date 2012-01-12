/*
 * =====================================================================================
 *
 *       Filename:  master_server.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/14/2011 01:09:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef _MASTER_SERVER_H
#define _MASTER_SERVER_H


const int32_t  PORT_MASTER = 5555;

struct master_server
{
	struct sockaddr_in addr_in;
	int listen_socket_fd;
	
	 struct worker *worker_joined;
	 int32_t worker_count;
};








#endif
