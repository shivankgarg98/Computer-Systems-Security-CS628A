#include <stdio.h>

int main()
{
	volatile int number = 0;
	char buffer[8];

	printf("number=%d\n", number);
	gets(buffer);
	printf("number=%d\n", number);
	return 0;
}

/**
 * $ python -c 'print "a"*8' | ./stack0 
 * $ python -c 'print "a"*9' | ./stack0 
*/
