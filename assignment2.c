#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    // first child for ls
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        return 1;
    }
    else if (pid1 == 0) {
        printf("child 1 running ls...\n");
        fflush(stdout);
        execl("/bin/ls", "ls", NULL);
        perror("execl failed");
        return 1;
    }

    // second child for date
    pid2 = fork();
    if (pid2 < 0) {
        perror("fork failed");
        return 1;
    }
    else if (pid2 == 0) {
        printf("child 2 running date...\n");
        fflush(stdout);
        execl("/bin/date", "date", NULL);
        perror("execl failed");
        return 1;
    }

    // parent waits
    wait(NULL);
    wait(NULL);

    printf("Parent process done\n");
    return 0;
}
