#include <stdio.h>

int main(int argc, char* argv[])
{
	volatile int number = 0;
	char buffer[16];

	if (argc != 2) return 0;

	printf("number=%d\n", number);
	sprintf(buffer, "hello %s", argv[1]);
	printf("buffer=%s\n", buffer);
	printf("number=%d\n", number);

	printf("buffer addr: %p\n", buffer);
	printf("number addr: %p\n", &number);
	return 0;
}

/**
 * $ ./stack1 `python -c 'print "a"*8'` 
 * $ ./stack1 `python -c 'print "a"*9'` 
*/
