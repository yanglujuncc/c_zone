/*
 * =====================================================================================
 *
 *       Filename:  queue.c
 *
 *    Description:  ylj
 *
 *        Version:  1.0
 *        Created:  07/20/2011 01:58:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <queue.h>

int32_t queue_init(queue_head_t *_queue_head)
{
	if(_queue_head==NULL)
	{
		return -1;
	}
	_queue_head->nodes_count=0;
	_queue_head->tail=NULL;
	_queue_head->head=NULL;
	
	return 0;
}

int32_t enqueue(queue_head_t* _qhead ,queue_node_t* _new_node)
{
	if(_qhead==NULL||_new_node==NULL)
		return -1;

	if(_qhead->nodes_count==0)
	{
		_new_node->pre=NULL;
		-new_node->next=NULL;
		
		_qhead->head=_new_node;
		_qhead->tail=_new_node;
		_qhead->nodes_count=1;
		return 1;
	}
	
	if(_qhead->tail!=NULL)
	{
		_new_node->pre=_qhead->tail;
		_new_node->next=NULL;

		_qhead->tail->next=_new_node;
		_qhead->tail=_node;
		_qhead->nodes_count++;
		
		return _qhead->nodes_count;
	}
	else
		return -1;
 }



queue_node_t  *dequeue(queue_head* _qhead)
{
	if(_qhead==NULL)
		return NULL;
	if(_qhead->nodes_count==0||_qhead->head==NULL)
		return NULL;
	
	queue_node_t* old_head=_qhead->head;
	_qhead->head=old_head->next;
	
	if(_qhead->head!=NULL)
		_qhead->head->pre=NULL;
	
	
	return old_head;
	
}



/*   	
 *
int32_t loopqueue_inti(loopqueue_head_t** _head,int32_t total_nodes)
{

 	*_head = (loopqueue_head_t *)malloc(sizeof(loopqueue_head_t));
        if(*loopqueue_head==NULL)
        {
                return -1;
        }       
        
	
        (*loopqueue_head)->nodes_count=0;
        (*loopqueue_head)->tail=NULL;
        (*loopqueue_head)->head=NULL;
        
	
        return 0;
}
*/
