#include <spawn.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include <sys/wait.h>

extern char **environ;

void run_program(char **arg) {
    pid_t pid;

    int status;
    status = posix_spawn(&pid, 
        arg[0], NULL, NULL, arg, environ);
    
    if (status != 0) {
        errno = status;
        perror(arg[0]);
        exit(EXIT_FAILURE);
    }

    waitpid(pid, NULL, 0);
}

int main(void) {
    char *args1[3] = {"/bin/date",  "+%d-%m-%Y", NULL};
    run_program(args1);

    char *args2[2] = {"/bin/whoami",  NULL};
    run_program(args2);
}
