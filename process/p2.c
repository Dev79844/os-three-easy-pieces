#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    printf("hello, world (pid: %d)\n", (int)getpid());
    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if(rc == 0){
        printf("child process (pid:%d)\n", (int) getpid());
    }else{
        int rc_wait = wait(NULL);
        printf("parent process of %d (rc_wait: %d) (pid:%d)\n",rc, rc_wait, (int)getpid());
    }

    return 0;
}