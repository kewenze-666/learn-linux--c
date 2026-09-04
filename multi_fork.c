#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int num_processes = 3;//创建三个子进程
	for(int i = 0; i<num_processes;i++){
	pid_t pid = fork();
	if(pid == 0){
	//子进程，只负责自己的任务，然后立刻退出，防止递归fork
	printf("子进程 %d 启动,PID= %d ,我的父进程= %d \n",i,getpid(),getpid());
	sleep(2);//模拟干活，比如加载模型
	printf("子进程 %d 任务完成! \n",i);
	return 0;//子进程必须return ，不然会继续创建子孙
	}
}
	//父进程回收所有子进程1
	for(int i = 0;i < num_processes;i++){
		wait(NULL);
	}
	printf("所有子进程已完成,父进程退出。 \n");
	return 0;
}

