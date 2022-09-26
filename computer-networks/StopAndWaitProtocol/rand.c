#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand((unsigned int)time(NULL));
	int  r = (rand()%5+0);
	printf("%d",r);
}
