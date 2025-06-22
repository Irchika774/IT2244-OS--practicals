#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//normal c function that is executed as a threa
//wheen its name is specified in pathread_create()

void *helloworld(void *vargp)
{
    sleep(1);
    printf("Hello world \n");
    return NULL;
}

int main(){
    pthread_t thread_id;
    printf("Before Thread\n");
    pthread_create(&thread_id,NULL, helloworld,NULL);
    pthread_join(thread_id,NULL);
    printf("After Theread\n");
    exit(0);
}



//multi -thread process

#include <stdio.h>
#include <pathread.h>

//function to be executed by the thread
void* print_message(void* arg){
    char* message = (char*)arg;
    printf("%s\n",message);
    return NULL;
}

int main(){
    pthread_t thread1, thread2;

    //create first thread
    pthread_create(&thread1, NULL, print_message, "Hello from Thread 1!");

    //create second thread
    pthread_create(&thread2, NULL, print_message, "Hello from Thread 2!");


    //wait for both thread to finish 
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both thread completed. \n");
    return 0;
}


#include <stdio.h>
#include <pathread.h>

void* print_message(void* arg){
    char* message =(char*)arg;
    printf("%s\n",message);
    return NULL;
}

int main(){
    pthread_t threads[3]
    char*message[]={

    }
}


///parallel sum

#include <stdio.h>
#include <pthread.h>

#define SIZE 6

int arrr[SIZE] = {1,2,3,4,5,6};
int sum1 =0, sum2 =0;

void* sum_part1(void* arg){
    for (int i =0; i < SIZE/2; i++){
        sum1 
    }
    
}


//what is thread?
/*
A thread is a single sequence of instructions running in a program.

Multiple threads = multiple sequences running at once in the same program.

They share resources (like kitchen tools) but do different tasks.


*/ 