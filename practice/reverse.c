/*
 * =====================================================================================
 *
 *       Filename:  reverse.c
 *
 *    Description:  ylj
 *
 *        Version:  1.0
 *        Created:  08/03/2011 01:02:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>

void reverse(int x,int *y)
{
   int flag=1;
   int temp=1; 
   int remain=x;
   if(x<0)
   {
       flag=-1;
       remain=x*flag;
   }
   else if(x>0)
   {
	flag=1;
   }
   else 
	flag=0;
  
   int new_num=0;
   temp=0; 
 
   while(remain>0)
   {
 	new_num=remain%10;
	remain=remain/10;
	temp=temp*10+new_num;
   }

   *y=temp*flag;
}
bool check_reverse(int x,int y)
{
   if(x==0||y==0)
   {
	if(x!=y)
		return false;
	else 
		return true;
   }
   if(x*y<0)
  	return false;

  if(x<0)
  {
    x=x*(-1);
    y=y*(-1);
  }
 
  	

}
int main(int argc,char** argv)
{
   int y;
    reverse(123456,&y);
    printf("123456 reverse = %d\n",y);
    reverse(-123456,&y);
    printf("-123456 reverse = %d\n",y);
    reverse(123450,&y);
    printf("123450 reverse = %d\n",y);
    reverse(0,&y);
    printf("0 reverse = %d\n",y);

	return 0;
}

