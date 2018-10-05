#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
    key_t key;
    int shmid;
    char *string;
    key = ftok("Shared memory file",100);
    shmid = shmget(key,256,0666|IPC_CREAT);
    string = shmat(shmid, (void *)0,0);
    printf("Enter shared string\n");
    gets(string);
    shmdt(string);
    return 0;
}
