//
//  main.c
//  Ex7_1-1
//
//  Created by 赵桐 on 2020/6/4.
//  Copyright © 2020 赵桐. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    pid_t pid=-1;
    int stauts=-1;
    pid=fork();
    if (pid<0)
    {
        printf("Create childpid wrong!\n");
    }
    if (pid==0)
    {
        printf("This is a childpid!\n");
        system("ping 127.0.0.1 -c 10");
        exit(1);
    }
    if (pid>0)
    {
        system("gedit");
        wait(&stauts);
        printf("子进程：%d,推出码是：%d",pid,stauts);
        
    }
//    printf("Hello, World!\n");
    return 0;
}
