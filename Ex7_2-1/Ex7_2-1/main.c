//
//  main.c
//  Ex7_2-1
//
//  Created by 赵桐 on 2020/6/4.
//  Copyright © 2020 赵桐. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/stat.h>

void init_deamon(void);
int main(int argc, const char * argv[]) {
    // insert code here...
    int hour,min;
    scanf("%d:%d",&hour,&min);
    FILE * fp;
    time_t timep;
    struct tm * tp;
    init_deamon();
    while(1)
    {

        time(&timep);
        tp=gmtime(&timep);
        if((tp->tm_hour+8)==hour && tp->tm_min==min)
        {
            if((fp=fopen("exp7-3.log","a+"))>=0)
            {
                fprintf(fp,"您设定的时间到了！当前时间是%d:%d\n",hour,min);
                fclose(fp);
            }

        }
        sleep(5);
    }
    return 0;
}
void init_deamon(void)
{
    pid_t child;
    int i;
    child=fork();
    if(child>0)
        exit(0);
    else if (child<0)
    {
        perror("Create child wrong!\n");
        exit(1);
    }
    setsid();
    chdir("/tmp");
    umask(0);
    for (i=0; i<NOFILE; ++i) {
        close(i);
    }
    
}
