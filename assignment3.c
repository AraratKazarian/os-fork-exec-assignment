#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } 
    else if (pid == 0) {
        // child process
        execl("/bin/echo", "echo", "Hello from the child process", NULL);
        return 1;
    } 
    else {
        // parent process
        wait(NULL); 
        printf("Parent process done\n");
    }

    return 0;
}
