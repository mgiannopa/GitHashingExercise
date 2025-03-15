#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int sigint_count = 0;

void sigint_handler(int sig_num) {
    sigint_count++;
    printf(" Caught signal  times: %d\n", sigint_count);
    if (sigint_count >= 1) {
        signal(SIGINT, SIG_DFL);
    }
}

int main() {
    signal(SIGINT, sigint_handler);
    while(1) {
    }
    return 0;
}
