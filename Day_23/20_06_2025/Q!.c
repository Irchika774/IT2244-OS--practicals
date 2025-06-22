Q1)write a  c program that creates two threats.Each threats should print a messqage indicating it is running. 
The mAIN THREAD SHOULD WAIT FOR BOTH threads to finish before existing.


#include <stdio.h>
#include <pthread.h>

// Thread function
void* thread_function(void* arg) {
    int thread_num = *(int*)arg;
    printf("Thread %d is running.\n", thread_num);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int t1 = 1, t2 = 2;

    // Create the first thread
    if (pthread_create(&thread1, NULL, thread_function, &t1) != 0) {
        perror("Failed to create thread 1");
        return 1;
    }

    // Create the second thread
    if (pthread_create(&thread2, NULL, thread_function, &t2) != 0) {
        perror("Failed to create thread 2");
        return 1;
    }

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main thread exiting after both threads are done.\n");
    return 0;
}
