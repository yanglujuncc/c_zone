/*
 * =====================================================================================
 *
 *       Filename:  package.h
 *
 *    Description:  ylj
 *
 *        Version:  1.0
 *        Created:  07/14/2011 03:07:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#define PG_TYPE_CALL  1
#define PG_TYPE_RETURN  2
#define PG_TYPE_MAX  2

#define STATUS_OK  1
#define STATUS_ERROR  2
#define STATUS_MAX  2

#define DATA_MAX  512

#define PACKAGE_HEAD_OK  0
#define PACKAGE_HEAD_ERROR  -1

struct package_head
{
    int32_t package_type;
    int32_t status;
    int32_t call_service_ID;
    int32_t data_length;
    int32_t serial_number;
};

int32_t check_package_head(struct package_head* _package_head);

