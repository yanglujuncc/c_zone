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

struct master
{
 struct sockaddr_in;
 int32_t connection_fd;

 struct worker *worker_arrary;
 int32_t worker_count;

}

