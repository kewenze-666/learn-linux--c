#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main() {
	pid_t pid = fork();
	if (pid == 0) {
		printf("子进程 (PID=%d) 运行完毕,即将退出...\n",getpid());
}	else{
		printf("父进程(PID=%d)故意不调用 wait(),开始睡眠 30秒...\n",getpid());
		printf("赶快在另一个终端执行：ps aux | grep zombie\n");
		sleep(30);
		printf("父进程退出，僵尸进程被系统回收。\n");}
	return 0;
}



