#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *file = fopen("pids.txt", "w");

    pid_t pid = fork();
    if (pid == 0) {
        fprintf(file, "Child PID: %d\n", getpid());
    } else if (pid > 0) {
        fprintf(file, "Parent PID: %d\n", getpid());
    } else {
        perror("Fork failed");
    }

    fclose(file);
    return 0;
}
