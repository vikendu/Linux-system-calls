#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_buffer
{
long msg_type;
char msg_text[50];
}message;

int main()
{
key_t key;
int msg_id;
int pid;
key = ftok("progfile", 65);

msg_id = msgget(key, 0666|IPC_CREAT);
message.msg_type = 1;

printf("Write data");

gets(message.msg_text);
pid = fork();

if(pid == 0)
{
msgsnd(msg_id, &message, sizeof(message),0);
printf("parent process\n");
printf("Data sent is: %s \n", message.msg_text);
}
else
{
msgrcv(msg_id,&message,sizeof(message),1,0);
printf("Child Process\n");
printf("Recieved message is %s \n",message.msg_text);
}
return 0;
}
