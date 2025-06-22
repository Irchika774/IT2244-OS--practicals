#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;

void* increment(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* decrement(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&lock);
        counter--;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t inc_thread, dec_thread;

    pthread_mutex_init(&lock, NULL);

    // Create threads
    pthread_create(&inc_thread, NULL, increment, NULL);
    pthread_create(&dec_thread, NULL, decrement, NULL);

    // Wait for both threads to complete
    pthread_join(inc_thread, NULL);
    pthread_join(dec_thread, NULL);

    printf("Final value of counter: %d\n", counter);

    pthread_mutex_destroy(&lock);
    return 0;
}
