#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#define MAX_CMD_LEN 1024
#define MAX_ARGS 64
int main(){
	char cmd[MAX_CMD_LEN];
	char *args[MAX_ARGS];
	char *token;
	while(1){
		//1.显示提示符
		printf("minishell>");
		fflush(stdout);
		//2.读取用户输入
		if(fgets(cmd,sizeof(cmd),stdin) == NULL){
			printf("\n");
			break;//遇到ctrl+D 退出
}
		//3.去掉末尾换行符
		cmd[strcspn(cmd,"\n")] = '\0';
		//4.跳过空输入
		if(strlen(cmd) == 0){
			continue;
}
		//5.解析命令为参数组（用空格分割）
		int i = 0;
		token = strtok(cmd," ");
		while(token != NULL && i < MAX_ARGS - 1) {
			args[i++] = token;
			token = strtok(NULL," ");
}
		args[i] = NULL;//exec 要求以NULL结尾
		//6.内置命令：exit
		if(strcmp(args[0],"exit") == 0){
			break;
}
		//创建子进程执行命令
		pid_t pid = fork();
		if(pid == 0){
			//子进程：执行命令
			execvp(args[0],args);
			//如果exec失败，打印错误并退出
			perror("execvp");
			exit(1);
		}else if(pid > 0){
			//父进程：等待子进程结束
			wait(NULL);
		}else{
			perror("fork");
}

}
		return 0;
}
