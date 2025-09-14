#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    printf("Process started: PID=%d, Parent PID=%d\n", getpid(), getppid());

    fork();
    fork();
    fork();

    printf("After fork: PID=%d, Parent PID=%d\n", getpid(), getppid());

    return 0;
}
