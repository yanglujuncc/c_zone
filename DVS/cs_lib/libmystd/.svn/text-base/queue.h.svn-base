/*
 * =====================================================================================
 *
 *       Filename:  queue.h
 *
 *    Description:  ylj
 *
 *        Version:  1.0
 *        Created:  07/20/2011 01:35:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *        Company:
 *
 * =====================================================================================
 */


#ifndef  QUEUE_H_
#define  QUEUE_H_


typedef struct queue_head{
    int32_t nodes_count;
    struct queue_node* tail;
    struct queue_node* head;

}queue_head_t;


typedef struct queue_node{
    struct queue_node* next;
    struct queue_node* pre;
}queue_node_t;


//malloc + initial
int32_t queue_init(queue_head_t **_head);

//int32_t loopqueue_inti(loopqueue_head_t** _head,int32_t total_nodes);

int32_t enqueue(queue_head_t* _qhead ,void* _node_content);

/*
 * return NULL
 */
queue_node_t  *dequeue(queue_head* _qhead);


#define queue_entry(ptr,type,member) \
    ( (type*)((char*)(ptr)-(unsigned long)(&((type*)0)->member) ))


#endif
