#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler function for SIGINT
void sigint_handler(int sig_num) {
    printf(" SIGINT signal caught!\n");
    exit(0);
}

int main() {
    // Register sigint_handler for SIGINT signal
    signal(SIGINT, sigint_handler);

    // Infinite loop to keep the program running
    while(1) {
    }

    // The program will never reach this point because it's stuck in the infinite loop
    return 0;
}
