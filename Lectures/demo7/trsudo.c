#include <assert.h>
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
        assert(ptrace(PTRACE_TRACEME, 0, NULL, NULL) >= 0);
        assert(raise(SIGSTOP) == 0);
        char *argv[] = { "sudo", NULL };
        char *envp[] = { "USER=pramod", NULL };
        execve("/usr/bin/sudo", argv, envp);
    }
    else {
        int status;
        pid_t result;
        FILE* log = fopen("log.txt", "wt");
        if (log == NULL) log = stdout;

        // wait for child to stop.
        waitpid(child, &status, 0);
        assert(WIFSTOPPED(status) && WSTOPSIG(status) == SIGSTOP);
        do {
            orig_rax = ptrace(PTRACE_PEEKUSER, child, 8 * ORIG_RAX, NULL);
            if (orig_rax != -1) {
                fprintf(log, "The child made a system call %ld\n", orig_rax);
            }
            ptrace(PTRACE_SYSCALL, child, NULL, NULL);
            result = waitpid(child, &status, WNOHANG);
        } while(!WIFEXITED(status) && result != -1);
    }
    return 0;
}
