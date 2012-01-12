/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  ylj
 *
 *        Version:  1.0
 *        Created:  07/20/2011 11:34:10 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef _LIST_H
#define _LIST_H



typedef struct list_head{
	int32_t nodes_count;
	struct list_node* first;
	struct list_node* tail;
}list_head_t;



struct list_node{
	struct list_node *pre;
	struct list_node *next;
		
}list_node_t;

int32_t list_pushback( list_head_t*_list,list_node_t* _newnode);

#define queue_entry(ptr,type,member) \
        ( (type*)((char*)(ptr)-(unsigned long)(&((type*)0)->member) ))





#endif
