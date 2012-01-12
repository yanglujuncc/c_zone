/*
 * =====================================================================================
 *
 *       Filename:  test_client.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/14/2011 12:53:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

//#include "master_client.h"
#include "worker_client.h"


int main(int argc,char**argv)
{
	/*  	
	struct master_client _master;
	
         //intial
 	_master.connection_fd=-1;
	_master.addr_in.sin_family=AF_INET;
	_master.addr_in.sin_port=htons(PORT_MASTER);
	_master.addr_in.sin_addr.s_addr = inet_addr(IP_MASTER);
	
	_master.worker_count=-1;
  
	if(!connect_to_master(&_master))
	{
		printf("connect_to_master success\n");
	}	
	else
	{
		printf("connect_to_master failed\n");
		
	}
	close_connect_master(&_master);	
	*/

	struct worker_client _worker;
	
         //intial
 	_worker.connection_fd=-1;
	_worker.addr_in.sin_family=AF_INET;
	_worker.addr_in.sin_port=htons(PORT_WORKER);
	_worker.addr_in.sin_addr.s_addr = inet_addr(IP_WORKER);
	
	_worker.service_count=-1;
  
	if(!connect_to_worker(&_worker))
	{
		printf("connect_to_worker success\n");
	}	
	else
	{
		printf("connect_to_worker failed\n");
		
	}
	close_connect_worker(&_worker);	

	return 0;
}

