/*
 * =====================================================================================
 *
 *       Filename:  new.cpp
 *
 *    Description:  gg
 *
 *        Version:  1.0
 *        Created:  07/06/2011 03:19:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
//#include <new.h>
class base
{
  public:
	base()
	{
		a=b=c=0;
		std::cout<<"in base()"<<std::endl;
	}
	base(int aa,int bb,int cc):a(aa),b(bb)
	{
		c=cc;
		std::cout<<" in base(int aa, int bb, int cc)"<<std::endl;
	}
 private:
  	int a;
	int b;
 	int c;
};
int main (int argc,char** argv )
{
	char* buf=(char *)malloc(sizeof(base));
	base* b=(base*)buf;
    // base* bb=	new(b)base;
     	new(b)base(1,2,3);
 //	std::cout<<bb<<std::endl;
	std::cout<<b<<std::endl;
	return 0;
}
