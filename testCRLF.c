#include <stdio.h>

int main()
{
	char a,b;
	
	a=getchar();
	
	if(a=='\r')
		printf("a=\\r");
	else if(a=='\n')
		printf("a=\\n");

	b=getchar();
	if(b=='\r')
		printf("b=\\r");
	else if(b=='\n')
		printf("b=\\n");

	return 0;


}
