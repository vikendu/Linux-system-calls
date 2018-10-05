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
    printf("Message read from shared memory:- %s \n", string);
    //gets(string);
    shmdt(string);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
