#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>
#include <sys/reg.h>

int main()
{   pid_t child;
    long orig_rax;
    child = fork();
    if(child == 0) {
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        printf("hello, world!\n");
    }
    else {
        int status;
        pid_t result;
        result = waitpid(child, &status, WNOHANG);
        orig_rax = ptrace(PTRACE_PEEKUSER,
                          child, 8 * ORIG_RAX,
                          NULL);
        if (orig_rax != -1) {
            printf("The child made a system call %ld\n", orig_rax);
        }
    }
    return 0;
}
