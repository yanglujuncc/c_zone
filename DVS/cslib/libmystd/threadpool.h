/*
 * =====================================================================================
 *
 *       Filename:  threadpool.h
 *
 *    Description:  ylj
 *
 *        Version:  1.0
 *        Created:  07/19/2011 05:52:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *        Company:
 *
 * =====================================================================================
 */
#ifndef THREADPOOL_H_
#define THREADPOOL_H_


#include <pthread.h>

#include "queue.h"
#include "list.h"

#define MAX   (int32_t)20
#define JOB_LIST_SIZE  (int32_t)50

typedef struct threadpool{

    int32_t threads_max_num;
    int32_t total_count;
    int32_t idle_count;

    list_head_t workers_list;
    queue_head_t jobs_queue;

}threadpool_t;


typedef struct job{
    void* (runfunction) (void* _data_ptr,int32_t _data_length);
    void * data_ptr;
    int32_t data_length;

    queue_node_t link_node;

}job_t;

typedef struct worker_thread{
    int32_t _index;
    pthread_t _pthread;

    list_node_t link_node;
}worker_thread_t;




int32_t threadpool_init(struct threadpool* _thdpool,int32_t worker_init,int32_t workerlist_length,int32_t jobqueue_length);

int32_t thread_create(struct threadpool* _thdpool,int32_t _num);

int32_t addjob(struct threadpool * _thdpool,struct job* _newjob);

int32_t



void *thread_run(void *arg)
{
    threadpool_t* thd_pool=(threadpool_t *)arg;

    if(thd_pool==NULL)
        return -1;


    while(true)
    {
            /*one work per loop */
        while(thd_pool->jobs_queue->nodes_count==0)
        {

            thd_pool->idle_count++;

            wait();

            thd_pool->idle_count--;

        }
    }
}


#endif


