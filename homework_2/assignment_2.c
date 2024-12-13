#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#define ARR_SIZE 20

typedef struct {
  int* arr;
  size_t size;
} thread_data_t;


void* calc_arr_sum(void* arg) {
    thread_data_t* arrData = (thread_data_t*)arg;
    long long sum = 0;
    for (size_t i = 0; i < arrData->size; i++) {
      sum += arrData->arr[i];
    }
    
    pthread_t threadId = pthread_self();
    printf("Thread ID: %lu, Sum: %lld\n", threadId, sum);
}

int main() {
    pthread_t thread1, thread2;

    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++) {
      arr[i] = i;  // Custom initialization
    }

    thread_data_t data1;
    data1.arr = arr;
    data1.size = ARR_SIZE / 2;
    
    thread_data_t data2;
    data2.arr = arr + ARR_SIZE / 2;
    data2.size = ARR_SIZE / 2;

    if (pthread_create(&thread1, NULL, &calc_arr_sum, (void*) &data1) != 0) {
        printf("Thread 1 failed!");
        return 1;
    }

    if (pthread_create(&thread2, NULL, &calc_arr_sum, (void*)&data2) != 0) {
        printf("Thread 2 failed!");
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}