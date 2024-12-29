#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int sigint_count = 0;

void custom_handler(int sig) {
    sigint_count++;
    printf("Signal %d caught! Count: %d\n", sig, sigint_count);
    if (sigint_count == 2) {
        signal(SIGINT, SIG_DFL); // Restore default behavior
    }
}

int main() {
    signal(SIGINT, custom_handler);
    printf("Press Ctrl+C (up to 3 times)...\n");
    while (1);
    return 0;
}
