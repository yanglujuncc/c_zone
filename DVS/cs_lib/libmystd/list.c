/*
 * =====================================================================================
 *
 *       Filename:  list.c
 *
 *    Description:  ylj
 *
 *        Version:  1.0
 *        Created:  07/20/2011 03:41:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *        Company:
 *
 * =====================================================================================
 */
int32_t list_pushback( list_head_t*_list,list_node_t* _newnode)
{
    if(_list==NULL)
    {
        return -1;
    }

    if(_list->nodes_count==0)
    {
        _list->first=_newnode;
        _list->tail=_newnode;
        _list->nodes_count++;

        _newnode->pre=NULL;
        _newnode->next=NULL;
        return 0;
    }

    if(_list->tail==NULL)
    {
        return -1;
    }

    _list->tail->next=_newnode;
    _newnode->pre=_list->tail;
    _newnode->next=NULL;
    _list->tail=_newnode;


    return 0;

}

