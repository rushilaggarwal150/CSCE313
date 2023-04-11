#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
char *custom_env[] = {"USER=Pikachu", "PATH=/tmp", NULL};

int main(void)
{
    printf("Running parent process PID: %i\n", getpid());
    printf("\n");
    // TODO
    char *first[] = {"echoall", "Bandicoot", "Pacman", NULL};
    if(fork() == 0){
        printf("Running child process PID: %i\n", getpid());
        execle("./echoall", first[0], first[1],first[2], NULL, custom_env, NULL, NULL);
    }

    sleep(1);

    char *sec[] = {"./echoall", "echoall", "Spyro", NULL};
    if(fork() == 0){
        printf("Running child process PID: %i\n", getpid());
        execlp(sec[0], sec[1], sec[2], NULL);
    }
    exit(0);
}