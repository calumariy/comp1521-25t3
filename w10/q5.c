#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void *thread_function(void *data) {
    char *message = (char *)data;

    while (1) {
        puts(message);
    }

    return NULL;
}

int main(void) {
    pthread_t tid;
    int s;

    s = pthread_create(&tid, 
        NULL, thread_function, "Hello\n");

    if (s != 0) {
        errno = s;
        perror("thread");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        puts("there\n");
    }
    
}
