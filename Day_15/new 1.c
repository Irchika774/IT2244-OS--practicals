
#include <stdio.h>
#include <unistd.h>

int main(){
	return 0;
	
}


#include <stdio.h>
#include <unistd.h>

int main(){
	fork();
	printf("Hello world!\n");
	return 0;
}

vi hello.c
gcc hello.c -o hello
./hello

#include <stdio.h>
#include <unistd.h>

int main(){
	fork();
	fork();
	printf("Hello world!\n");
	return 0;
}

vi e1.c

#include <stdio.h>
#include <unistd.h>

int main(){

int f1=fork();
if(f1==0){
	printf("I am a child process,  my id is %d\n",getpid());
}
else{
	printf("I am the parent process, my id is %d\n",getpid());
}
	return 0;
	
}


//print numbers from 1 to 10
//1 to 5 should be print by child process and 
//from 6 to 10 should be parent process
//calculate summation of those number

vi e2.c

#include <stdio.h>
#include <unistd.h>

int main(){
int sum=0;
int f1=fork();
if(f1==0){
	printf("I am child My id is %d\n",getpid());
	for(int i=1;i<6;i++){
		printf("%d\n",i);
		sum=sum+i;
	}
	
}
else{
	printf("I am child My id is %d\n",getpid());
	for(int i=6;i<=10;i++){
		printf("%d\n",i);
		sum=sum+i;
	}
}
   printf("sum is : %d\n",sum);
	return 0;
	
}
gcc e2.c -o e2
./e2

#include <stdio.h>
#include <unistd.h>

int main(){
int sum=0;
int f1=fork();
int n;
if(f1==0){
        printf("I am child My id is %d\n",getpid());
        n=1;

}
else{
        printf("I am child My id is %d\n",getpid());
        n=6;
}

        for(int i=n;i<n+5;i++){
                printf("%d\n",i);
                sum=sum+i;
        }
   printf("sum is : %d\n",sum);
        return 0;

}
~
