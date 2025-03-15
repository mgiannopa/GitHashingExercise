#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_CHILDREN 4

int main() {
    int pipes[NUM_CHILDREN][2]; // One pipe for each child
    char characters[NUM_CHILDREN];
    pid_t child_pids[NUM_CHILDREN]; // Store child PIDs

    // Create pipes
    for (int i = 0; i < NUM_CHILDREN; ++i) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    // Create child processes
    for (int i = 0; i < NUM_CHILDREN; ++i) {
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {  // Child process
            close(pipes[i][1]); // Close write end of the pipe
            read(pipes[i][0], &characters[i], sizeof(char));
            close(pipes[i][0]); // Close read end of the pipe

            // Print PID and the entered character
           printf("\nChild process %d (PID %d) received character: %c\n", i + 1, getpid(), characters[i]);
           exit(EXIT_SUCCESS);
        } else {
            child_pids[i] = pid;  // Store the PID of the child process
        }
    }

    // Parent process
    for (int i = 0; i < NUM_CHILDREN; ++i) {
        close(pipes[i][0]); // Close read end of the pipe
    }

    // Read characters from the user and send them to child processes
    for (int i = 0; i < NUM_CHILDREN; ++i) {
        printf("Enter character for child process %d: ", i + 1);
        scanf(" %c", &characters[i]);
        write(pipes[i][1], &characters[i], sizeof(char));
        close(pipes[i][1]); // Close write end of the pipe
    }

    // Print the characters in ascending order
    printf("\nSummary in ascending order:\n");
    for (int i = 0; i < NUM_CHILDREN; ++i) {
        printf("Child process %d (PID %d) received character: %c\n", i + 1, child_pids[i], characters[i]);
    }

    return 0;
}
