#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
	int fd[2],nbytes;
	pid_t childpid;
	char string[] = "Hello, child\n";
	char readbuffer[80];
	pipe(fd);
	if((childpid = fork()) == -1) {
		perror("Fork failed\n");
		exit(1);
	}
	if(childpid == 0) {
		write(fd[1],string,strlen(string)+1);
		exit(0);
	}
	else {
		nbytes = read(fd[0],readbuffer,sizeof(readbuffer));
		printf("Received string from child is %s",readbuffer);
	}
	return 0;
}

