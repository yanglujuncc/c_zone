
#include<stdio.h>

static char buff [256];
static char* string;
int main ()
{
printf ("Please input a string: ");
gets (string);
printf ("\nYour string is: %s\n", string);
return 0;
}
 
