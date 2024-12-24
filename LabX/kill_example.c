#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void signal_handler(int sig) {
    if (sig == SIGUSR1) {
        printf("Child: Received SIGUSR1 from parent\n");
        exit(0); 
    }
}

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        signal(SIGUSR1, signal_handler);
        printf("Child: Waiting for signal from parent\n");
        pause();
    } else {
        // Parent process
        sleep(1);
        printf("Parent: Sending SIGUSR1 to child\n");
        kill(pid, SIGUSR1);
        wait(NULL);
        printf("Parent: Child process terminated\n");
    }

    return 0;
}