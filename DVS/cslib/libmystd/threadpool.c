/*
 * =====================================================================================
 *
 *       Filename:  threadpool.c
 *
 *    Description:  yanglujun
 *
 *        Version:  1.0
 *        Created:  07/20/2011 04:06:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include "threadpool.h"



int32_t threadpool_init(struct threadpool* _thdpool,int32_t worker_init,int32_t workerlist_length,int32_t jobqueue_length);

int32_t thread_create(struct threadpool* _thdpool,int32_t _num);

int32_t addjob(struct threadpool * _thdpool,struct job* _newjob);




void *thread_run(void *arg)
{
        threadpool_t* thd_pool=(threadpool_t *)arg;

        if(thd_pool==NULL)
                return -1;
                       
                       
        while(true)    
        {              
                        /* one work per loop */
                while(thd_pool->jobs_queue->nodes_count==0)
                {      
                        thd_pool->idle_count++;
                        wait();
                        thd_pool->idle_count--;
		}
	
		job_t *_job = getjob(_thd_pool);
		
		if(_job == NULL)
			continue;
		
		dojob(_job);		
		     
     	}
}

job_t *getjob(threadpool_t* _thd_pool)
{
	if(_thd_pool==NULL)
		return NULL;
	if(_thd_pool->jobs_queue->nodes_count==0)
		return NULL;
	
	queue_node_t  *_queuenode=dequeue(_thd_pool->jobs_queue);
	job_t * _job=queue_entry(_queuenode,job_t,link_node);
	
			
	return _job;	

}

void dojob(job_t *_job)
{
	if(_job==NULL)
		return ;
	_job->runfunction(_job->data_ptr,_job->data_length);
		return ;
}

