#include <sys/types.h>
#include "apue.h"
int glob = 3;

int main(void){
	pid_t pid1;
	pid_t pid2;
	char ch = 'A';
	int count = 0;
	
	
	if((pid2 = fork()) < 0)
		err_sys("fork error");
	else if(pid2 == 0){
		ch = 'C';	
		glob++;
				
	}
	if(glob == 3 && (pid1 = fork()) < 0)
		err_sys("fork error");
	else if(pid1 == 0){
		ch = 'B';		
		glob +=2;
	}
	if(glob == 3){
		usleep(10);
	}else if(glob =4){
		usleep(4);
	}
	for(int i = 0; i < 10; i++){
		count++;
		printf("%d,  %c, %d\n", getpid(), ch, count);
	}
	exit(0);
}
