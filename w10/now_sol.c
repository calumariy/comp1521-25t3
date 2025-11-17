#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

// extern means the variable is defined somewhere else.
// In this case, the variable is defined by the system environment.
extern char **environ;

// Spawns a process and waits for it to die.
// Input is the argv array of the process function.
void spawn_and_wait_and_count_output(char **args)
{
    // step 1: make pipe
    // step 2: make file actions, and tell file actions to set stdout = my pipe, and close the file when done
    // step 3: spawn process
    // step 4: read pipe and wait for process to exit!

    int p[2];
    if (pipe(p) != 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }


    posix_spawn_file_actions_t file_actions;   
    int s;
    if ((s = posix_spawn_file_actions_init(&file_actions)) != 0) {
        errno = s;
        perror("init file actions");
        exit(EXIT_FAILURE);
    }

    // close read end
    if (posix_spawn_file_actions_addclose(&file_actions, p[0]) != 0) {
        perror("posix_spawn_file_actions_init");
        exit(EXIT_FAILURE);
    }

    // stdout = write end
    if (posix_spawn_file_actions_adddup2(&file_actions, p[1], 1) != 0) {
        perror("posix_spawn_file_actions_init");
        exit(EXIT_FAILURE);
    }


    pid_t pid;
    int spawn_status = posix_spawn(&pid, args[0], &file_actions, NULL, args, environ);
    // args[0] is the file path.
    // array of arguments (args) must be NULL terminated.
    if (spawn_status != 0) {
        errno = spawn_status;
        // perror prints out an appropriate error message depending on errno.
        perror("posix_spawn");
        exit(EXIT_FAILURE);
    }

    int spawn_exit_status;

    close(p[1]);

    FILE *f = fdopen(p[0], "r");
    char line[256];
    if (fgets(line, sizeof line, f) == NULL) {
        fprintf(stderr, "no output\n");
        exit(EXIT_FAILURE);
    }

    printf("output captured from %s was [%d]: '%s'\n", args[0], strlen(line), line);

    if (waitpid(pid, &spawn_exit_status, 0) == -1) {
        perror("waitpid");
        // Prints waitpid: The error described by errno's error code
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    // Creates an array of strings for the input argv of each function.
    // NULL terminated to mark the end of the argument list.
    char *date_argv[] = {"/bin/date", "+%d-%m-%Y", NULL};
    // Run the date program with the argument "+%d-%m-%Y".
    spawn_and_wait_and_count_output(date_argv);

    char *time_argv[] = {"/bin/date", "+%T", NULL};
    // Run the time program with argument "+%T".
    spawn_and_wait_and_count_output(time_argv);

    char *user_argv[] = {"/usr/bin/whoami", NULL};
    spawn_and_wait_and_count_output(user_argv);

    // The -f flag is short for 'full': print full output, not shortened.
    char *hostname_argv[] = {"/bin/hostname", "-f", NULL};
    spawn_and_wait_and_count_output(hostname_argv);

    char *working_dir_argv[] = {"/usr/bin/realpath", ".", NULL};
    spawn_and_wait_and_count_output(working_dir_argv);
}