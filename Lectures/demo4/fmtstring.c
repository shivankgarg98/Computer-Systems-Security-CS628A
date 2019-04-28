#include <stdio.h>

int main(int argc, char* argv[])
{
	volatile long long int a = 0xabcd1234cafefeed;
	volatile long long int b = 0x9876fedcface1eed;
	volatile long long int x = 0xc0def123deadbeef;
	printf(argv[1]);
	// these three lines are needed so that gcc doesn't
	// optimize away the variables.
	printf("%p/%llx\n", &a, a);
	printf("%p/%llx\n", &b, b);
	printf("%p/%llx\n", &x, x);
	return 0; 
}
/*
  $ msg=`python3 -c "print ('%llx ' * 20)"`
  $ ./fmtstring "$msg"
*/
