#include <pwd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
   struct passwd *pwd;
   pwd = getpwuid(getuid());
   assert (pwd != NULL);
   printf("Name: %s; UID: %ld\n", pwd->pw_name, (long) pwd->pw_uid);
   return 0;
}
