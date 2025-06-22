Q2)write a programm to create 5 threads. Each thread should print its thread ID and then exit.
 the main thread ID tand then exist. ^The main thread should join all threads and print a completion message.


 #include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

// Thread function
void* thread_function(void* arg) {
    pthread_t tid = pthread_self();
    printf("Thread %d: ID = %lu\n", *(int*)arg, tid);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Main thread info
    pthread_t main_tid = pthread_self();
    printf("Main thread ID = %lu\n", main_tid);
    printf("All threads have completed. Exiting main thread.\n");

    return 0;
}
