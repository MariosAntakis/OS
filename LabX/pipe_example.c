#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100

int main() {
    int pipe_fd[2]; 
    pid_t pid;
    char write_msg[] = "Hello from parent!";
    char read_msg[BUFFER_SIZE];

    if (pipe(pipe_fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        close(pipe_fd[1]); 
        read(pipe_fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(pipe_fd[0]); 
    } else {
        // Parent process
        close(pipe_fd[0]);
        write(pipe_fd[1], write_msg, strlen(write_msg) + 1);
        printf("Parent sent: %s\n", write_msg);
        close(pipe_fd[1]); 
        wait(NULL);
    }

    return 0;
}