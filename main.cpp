#include <unistd.h>
#include <cstdio>
#include <semaphore.h>
#include <wait.h>

int main() {
    int a = 0;
    sem_t sem;
    sem_init(&sem, 0, 1);
    int pid = fork();
    if (pid == 0){
        sem_wait(&sem);
        a++;
        printf("a = %d\n", a);
        sem_post(&sem);
    } else {
        wait(&pid);
        sem_destroy(&sem);
    }
    return 0;
}