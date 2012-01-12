/*
 * =====================================================================================
 *
 *       Filename:  package.c
 *
 *    Description:  ylj
 *
 *        Version:  1.0
 *        Created:  07/14/2011 03:37:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include "*package.h"


int32_t check_package_head(struct package_head* _package_head)
{
	if(_package_head==NULL){
		return PACKAGE_HEAD_ERROR;
	}
	if(_package_head->package_type>PG_TYPE_MAX)
	{
		return PACKAGE_HEAD_ERROR;
	}
	if(_package_head->status>STATUS_MAX)
	{
		return PACKAGE_HEAD_ERROR;
	}
	if(_package_head->data_length>DATA_MAX)
	{
		return PACKAGE_HEAD_ERROR;
	}
    	
	return PACKAGE_HEAD_OK;
}
