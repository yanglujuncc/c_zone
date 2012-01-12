/*
 * =====================================================================================
 *
 *       Filename:  helloword_sevice.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/14/2011 04:19:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <string.h>

char* HELLOWORD = "helloword";
int32_t helloword_service(char* input_data,int32_t intput_data_count,char**output_data_ptr,int32_t* output_data_cout)
{
	char* helloword_str=(char*)malloc(strlen(HELLOWORD)+1);
	strcpy(helloword_str,HELLOWORD);
	*output_data_ptr=helloword_str;
	*output_data_cout=strlen(HELLOWORD)+1;
	return 0;
}
