#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define MAX 100000

int cnt = 0;
void * Count(void *a){
	int i,temp;
	sem_wait(&mutex);
	for(i=0;i<MAX;i++){
		temp = cnt;
		temp = temp+1;
		cnt = temp;
	}
	printf("count=%d\n",cnt);
	sem_post(&mutex);

}
int main(){
pthread_t tid1,tid2;
pthread_create(&tid1,NULL,Count,NULL);
pthread_create(&tid2,NULL,Count,NULL); 
pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
printf("%d \n",cnt);

}

