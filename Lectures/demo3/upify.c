#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char buffer[16];
	int i;

	gets(buffer);
	for(i=0; i < strlen(buffer); i++) {
		buffer[i] = _toupper(buffer[i]);
	}
	puts(buffer);

	return 0;
}

// python2.7 -c 'print "a"*128' > inp1
// for i in 16 32 48 64 80 96 112; do echo $i; python upify.py $i | ./upify ; done
