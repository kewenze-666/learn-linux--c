#include<stdio.h>
#include<unistd.h>
int main(){
	pid_t pid = fork();
	if(pid = 0){
		sleep(5);
		printf("我是子进程(PID=%d),我的父进程现在变成了%d\n",getpid(),getpid());
		printf("如果父PID是1,说明我被init进程收养了!\n");
	}else {
	printf("我是父进程(PID=%d),我这就死了，儿子再见!\n",getpid());
}
	return 0;
}
