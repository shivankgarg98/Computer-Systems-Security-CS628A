#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
	FILE* fp = fopen("time.log", "at");
	fprintf(fp, "time is %ld\n", time(NULL));
	fclose(fp);
	return 0;
}
