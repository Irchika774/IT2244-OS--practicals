Q5)Implement  a theread function that takes an intiger arguement, squares it,
   and returns the result to the mAIN THREAD using pthread_exit and pthread join.


   #include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function to square a number
void* square_number(void* arg) {
    int num = *(int*)arg;
    int* result = malloc(sizeof(int));  // Dynamically allocate memory for result
    if (result == NULL) {
        perror("Memory allocation failed");
        pthread_exit(NULL);
    }
    *result = num * num;
    pthread_exit(result);  // Return the result
}

int main() {
    pthread_t thread;
    int input = 6;  // Example value to square
    int* result;

    // Create the thread
    if (pthread_create(&thread, NULL, square_number, &input) != 0) {
        perror("Thread creation failed");
        return 1;
    }

    // Wait for the thread to complete and get the result
    if (pthread_join(thread, (void**)&result) != 0) {
        perror("Thread join failed");
        return 1;
    }

    printf("Square of %d is %d\n", input, *result);
    free(result);  // Clean up
    return 0;
}
