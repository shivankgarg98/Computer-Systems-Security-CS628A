#include <utmp.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	struct utmp rec;
	FILE* fp = fopen("/var/run/utmp", "rb");
	if (fp == NULL) {
		perror("fopen");
		return 1;
	}

	while (!feof(fp)) {
		if(0 == fread(&rec, sizeof(rec), 1, fp)) break;
		if (rec.ut_type == USER_PROCESS) {
			printf("%-32s %-32s\n", rec.ut_user, rec.ut_line);
		}
	}
	fclose(fp);
	return 0;
}
