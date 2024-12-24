#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    FILE *file;

    file = fopen("pids.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        fclose(file);
        return 1;
    } else if (pid == 0) {
        // Child process
        fprintf(file, "Child PID: %d\n", getpid());
        printf("Child: Written PID to file\n");
    } else {
        // Parent process
        fprintf(file, "Parent PID: %d\n", getpid());
        printf("Parent: Written PID to file\n");
        wait(NULL);
    }

    if (fclose(file) != 0) {
        perror("Error closing file");
        return 1;
    }
    return 0;
}