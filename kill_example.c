#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig) {
    printf("Child received signal: %d\n", sig);
}

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // Παιδί
        signal(SIGUSR1, handle_signal);
        pause();  // Περιμένει σήμα
    } else if (pid > 0) {
        // Γονέας
        sleep(1);  // Περίμενε το παιδί να είναι έτοιμο
        kill(pid, SIGUSR1);
        printf("Parent sent signal\n");
    } else {
        perror("Fork failed");
    }
    return 0;
}
