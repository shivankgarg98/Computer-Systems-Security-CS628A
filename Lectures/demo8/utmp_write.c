#include <utmp.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if (argc != 2) {
		fprintf(stderr, "syntax error.\n");
		return 1;
	}
	struct utmp rec;
	FILE* fp = fopen("/var/run/utmp", "rb+");
	if (fp == NULL) {
		perror("fopen");
		return 1;
	}

	while (!feof(fp)) {
		if(0 == fread(&rec, sizeof(rec), 1, fp)) break;
		if (rec.ut_type == USER_PROCESS &&
			strcmp(rec.ut_user, argv[1]) == 0) {
			rec.ut_type = EMPTY;
			fseek(fp, -sizeof(rec), SEEK_CUR);
			if(fwrite(&rec, sizeof(rec), 1, fp) <= 0) {
				perror("fwrite");
				return 2;
			}
			printf("succeeded.\n");
		}
	}
	fclose(fp);
	return 0;
}

