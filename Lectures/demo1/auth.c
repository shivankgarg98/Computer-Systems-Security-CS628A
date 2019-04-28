#include <stdio.h>
#include <string.h>

int checkpwd(const char* pwd)
{
	int good = 0;
	char buffer[8];
	strcpy(buffer, pwd);
	if(strcmp(buffer, "blahblah") == 0) good = 1;
	if(strcmp(buffer, "wahhwahh") == 0) good = 1;
	return good;
}

int main(int argc, char* argv[])
{
	if (argc != 2) return 1;
	if (checkpwd(argv[1])) {
		printf("=====================\n");
		printf("|| access granted  ||\n");
		printf("=====================\n");
	} else {
		printf("denied!\n");
	}
	return 0;
}
