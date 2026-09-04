#include<stdio.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
int main(){
	int fd[2];
	pipe(fd);//申请管道，拿到读门fd[0]和写门fd[1]
	pid_t pid = fork();
	if(pid == 0){
	//这是子进程(负责收信)
	close(fd[1]);//收信的人把写门关闭
	char buffer[100];
	read(fd[0],buffer,sizeof(buffer));//从读门拿数据
	printf("子进程收到: %s\n",buffer);
	close(fd[0]);
}
	else{//这是父进程，负责发信
	close(fd[0]);//发信，把读门关闭
	char *msg = "Hello,Pipe!这是来自父进程的消息";
	write(fd[1],msg,strlen(msg) + 1);//往写门塞纸条
	close (fd[1]);
	wait(NULL);
}return 0;
}
