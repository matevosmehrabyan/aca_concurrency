#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>


void* print_run_info() {
    pthread_t threadId = pthread_self();
    printf("Thread %lu is running\n", threadId);
}

int main() {
    pthread_t thread1, thread2, thread3;

    if (pthread_create(&thread1, NULL, &print_run_info, NULL) != 0) {
        printf("Thread 1 failed!");
        return 1;
    }

    if (pthread_create(&thread2, NULL, &print_run_info, NULL) != 0) {
        printf("Thread 2 failed!");
        return 1;
    }

    if (pthread_create(&thread3, NULL, &print_run_info, NULL) != 0) {
        printf("Thread 3 failed!");
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}