#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
printf("[A]chengxvqidong!wodePIDshi%d",getpid());
pid_t pid=fork();
printf("[B]forkzhixingwanbi,dangqianjinchengPIDshi%d,forkfanhuidePIDshi%d\n",getpid(),pid);
if(pid==0){
	printf("[C]woshizijincheng!wodePIDbianliangshi0\n");
}else if(pid>0){
	printf("[D]woshifujincheng!wodePIDbianliangshi%d\n",pid);
}else{
printf("[E]chucuole\n");
}printf("[F]chengxvjieshu,PID%dtuichule\n",getpid());
return 0;
}
