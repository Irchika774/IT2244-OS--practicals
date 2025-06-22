Q3)Write a program thet creates a thread which prints numbers from 1 to 10 with a 1-second to delay between each
   number.the main thread should wait for this thread to finish.

   #include <stdio.h>
#include <pthread.h>
#include <unistd.h>  // for sleep()

// Thread function to print numbers 1 to 10 with delay
void* print_numbers(void* arg) {
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
        sleep(1);  // Delay of 1 second
    }
    return NULL;
}

int main() {
    pthread_t thread;

    // Create the thread
    if (pthread_create(&thread, NULL, print_numbers, NULL) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    printf("Thread finished. Main thread exiting.\n");
    return 0;
}
