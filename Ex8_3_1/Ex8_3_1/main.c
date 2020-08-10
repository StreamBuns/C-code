//
//  main.c
//  Ex8_3_1
//
//  Created by 赵桐 on 2020/6/15.
//  Copyright © 2020 赵桐. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    pid_t child;
    char order[30]="ps -ef|grep ";
    char str[10]={0};
    child = fork();
    if (child<0)
    {
        printf("创建子进程失败");
    }
    if (child==0)
    {
        exit(0);
    }
    else if (child>0)
    {
        sleep(2);
        printf("子进程的程序号是%d\n利用ps命令验证子进程状态：\n",child);
        sprintf(str,"%d",child);
        strcat(order, str);
        system(order);
        exit(0);
    }
//    printf("Hello, World!\n");
    return 0;
}
