#include <sys/msg.h> //for system calls
#include <stdio.h>  //for I/O functions
#include <string.h> //for string operations
#include <stdlib.h> //For exit
#include <unistd.h> //for fork()

#define MSGKEY 1111 //it s a unique key like mal box address
#define MAX_NAME_LEN 100
#define MAX_REGNO_LEN 100

//definre the structure of message
struct person {
    long mtype; // Message type
    int age;
    char name[MAX_NAME_LEN];
    char regno[MAX_REGNO_LEN];
};

int main() {
    int msqid;
    struct person p1, p2;
    int f = fork(); //it is like assigning 2 workers

    if (f == 0) {
        // Child process: Receiver
        msqid = msgget(MSGKEY, IPC_CREAT | 0666); //child gets access mailbox using MSGKEY (1111)
        if (msqid == -1) {
            perror("msgget failed");
            exit(EXIT_FAILURE);
        }

        int msg_size = sizeof(struct person) - sizeof(long);//messsage size
        
        //wait form amessage from parent
        if (msgrcv(msqid, &p2, msg_size, 0, 0) == -1) {
            perror("msgrcv failed");
            exit(EXIT_FAILURE);
        } else {
            //print received student data
            printf("Received Name: %s\n", p2.name);
            printf("Received RegNo: %s\n", p2.regno);
            printf("Received Age: %d\n", p2.age);
        }

        if (msgctl(msqid, IPC_RMID, NULL) == -1) {
            perror("msgctl failed");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process: Sender
        msqid = msgget(MSGKEY, IPC_CREAT | 0666);
        if (msqid == -1) {
            perror("msgget failed");
            exit(EXIT_FAILURE);
        }

        p1.mtype = 1;//like setting a tag for message type


        //user input(Gather student)
        printf("Enter Name: ");
        scanf("%s", p1.name);

        printf("Enter RegNo: ");
        scanf("%s", p1.regno);

        printf("Enter Age: ");
        scanf("%d", &p1.age);

        int msg_size = sizeof(struct person) - sizeof(long);//calculate data size


        //send th emessage(like sendinng student info to admin)
        if (msgsnd(msqid, &p1, msg_size, IPC_NOWAIT) == -1) {
            perror("msgsnd failed");
        } else {
            printf("Message sent successfully.\n");//confirmation
        }

        exit(0);//enter the parent process after sending
    }

    return 0;
}
