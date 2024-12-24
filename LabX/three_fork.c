#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2, pid3;

    // 1st fork
    pid1 = fork();
    if(pid1 < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if(pid1 == 0) {
        printf("Child1: Process ID: %d, Parent ID: %d \n", getpid(), getppid());
    } 
    else {
        // 2nd fork
        pid2 = fork();
        if(pid2 < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        else if(pid2 == 0) {
            printf("Child2: Process ID: %d, Parent ID: %d \n", getpid(), getppid());
        }
        else {
            // 3rd fork
            pid3 = fork();
            if(pid3 < 0) {
                perror("fork failed");
                exit(EXIT_FAILURE);
            }
            else if(pid3 == 0) {
                printf("Child3: Process ID: %d, Parent ID: %d \n", getpid(), getppid());
            }
            else {
                printf("Parent: Process ID = %d \n", getpid());
            }
        }
    }

    return 0;
}
