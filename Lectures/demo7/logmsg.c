#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[]) {
	char buffer[80];
	FILE* fp;

	if (argc != 2) {
		fprintf(stderr, "syntax error.\n");
		return 1;
	}
	fp = fopen("msg.log", "at");
	if (fp == NULL) {
		fprintf(stderr, "fopen failed.\n");
		return 2;
	}

    struct passwd *pwd;
    pwd = getpwuid(getuid());
	if (pwd == NULL) {
		fprintf(stderr, "getpwuid failed.\n");
		return 2;
	}
	sprintf(buffer, "%s@%ld: %s\n", pwd->pw_name, time(NULL), argv[1]);
	fwrite(buffer, strlen(buffer), 1, fp);
	fclose(fp);

	return 0;
}
