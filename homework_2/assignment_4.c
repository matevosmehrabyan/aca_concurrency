#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#define ARR_SIZE 10

typedef struct {
  int* arr;
  size_t size;
} thread_data_t;


void* calc_square(void* arg) {
    int num = *(int*)arg;    
    printf("Square of %d is %d\n", num, num * num);
}

int main() {
    pthread_t threads[10];

    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++) {
      arr[i] = i;  // Custom initialization
    }

    for (int i = 0; i < ARR_SIZE; i++) {
      if (pthread_create(&threads[i], NULL, &calc_square, (void*) &arr[i]) != 0) {
        printf("Thread %d failed!", i);
        // Here, we could join already running threads
        return 1;
      }
    }

    for (int i = 0; i < ARR_SIZE; i++) {
      pthread_join(threads[i], NULL);  // We also could check exit codes
    }

    return 0;
}