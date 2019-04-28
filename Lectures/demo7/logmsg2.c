#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

#define _GNU_SOURCE

void print_whoiam(const char* label) {
    struct passwd *pwd;
    pwd = getpwuid(getuid());
	if (pwd != NULL) {
		printf("[%s]: real username: %s; UID: %ld\n", 
			label, pwd->pw_name, (long) pwd->pw_uid);
	}
    pwd = getpwuid(geteuid());
	if (pwd != NULL) {
		printf("[%s]: effective username: %s; UID: %ld\n", 
			label, pwd->pw_name, (long) pwd->pw_uid);
	}
}
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
	print_whoiam("before");
	// drop back in privilege to be real uid
	if(setreuid(getuid(), getuid()) != 0) {
		fprintf(stderr, "Unable to drop privilege\n");
		return 1;
	}
	print_whoiam("after");

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
