#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <unistd.h>
#include <stdlib.h>

void start(int sig);
void run(int sig);
void stop(int sig);
void stops(int sig);
void the_end(int sig);
void get_off(int sig);

int main(int argc, const char *argv[])
{
    int fd[2];
    pipe(fd);
    pid_t fk = fork();
    if (fk > 0)
    {
        signal(SIGUSR1, run);
        signal(SIGUSR2, stops);
        signal(SIGTSTP, the_end);
        signal(SIGINT, SIG_IGN);
        signal(SIGQUIT, SIG_IGN);
        while (1)
            ;
    }
    else if (fk == 0)
    {
        signal(SIGINT, start);
        signal(SIGQUIT, stop);
        signal(SIGUSR1, get_off);
        signal(SIGUSR2, SIG_IGN);
        signal(SIGTSTP, SIG_IGN);
        while (1)
            ;
    }
    else
    {
        perror("fork is err");
    }
    
    return 0;
}

void start(int sig)
{
    if (sig == SIGINT)
    {
        printf("售票员:准备开车\n");
        kill(getppid(), SIGUSR1);
    }
}

void run(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("司机:车启动，请拉好扶手\n");
    }
}

void stop(int sig)
{
    printf("售票员:请停车\n");
    kill(getppid(), SIGUSR2);
}

void stops(int sig)
{
    printf("司机：车辆已制动\n");
}

void the_end(int sig)
{
    printf("司机:车辆到达终点站\n");
    kill(getpid()+1, SIGUSR1);//这里的写法可能会出现bug
    exit(0);
}

void get_off(int sig)
{
    printf("售票员:乘客朋友你们好，车辆到达终点站，请下车\n");
    exit(0);
}