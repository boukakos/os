#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);

    pid_t pid = fork();
    if (pid == 0) {
        // Παιδί
        close(fd[1]);  // Κλείσε την έξοδο
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
    } else if (pid > 0) {
        // Γονέας
        close(fd[0]);  // Κλείσε την είσοδο
        char message[] = "Hello from parent!";
        write(fd[1], message, strlen(message) + 1);
    } else {
        perror("Fork failed");
    }
    return 0;
}
