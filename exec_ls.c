#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	pid_t pid = fork();
	if(pid == 0){//子进程：变身成ls
		printf("子进程即将变身成 ls -l\n");
		execlp("ls","ls","-l",NULL);
		//如果exrc执行失败，才会继续执行下面这行
		perror("exec 失败");
		return 1;
	}else{
//父进程：等待子进程完毕
		wait(NULL);
		printf("子进程执行完毕，父进程退出。\n");
}
return 0;
}

