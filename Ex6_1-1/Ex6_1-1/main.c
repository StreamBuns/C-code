//
//  main.c
//  Ex6_1-1
//
//  Created by 赵桐 on 2020/5/29.
//  Copyright © 2020 赵桐. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//#include <error.h>
//#include <errno.h.>
#include <string.h>

char buf[100];
#define MSG_OS "-------欢迎使用图书馆座位订阅系统-------\n 1---订阅座位\n 2---解约座位\n 3---查询座位是否被占\n 4---推出系统\n"
#define MSG_SUBTIP "请输入你想要订阅的座位号：（0-100）和订阅的时间（单位，小时）\n"
#define MSG_CONTSUBTIP "请输入你想要取消订阅的座位号：（0-100）\n"
void ServiceSelect(int choice ,char* seat,int is_inq);
int main(int argc, const char * argv[]) {
    // insert code here...
    int n=1;
    int choice;
    char seat[3];
    float time;

    while(n>0)
    {
        printf(MSG_OS);
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf(MSG_SUBTIP);
                scanf("%s%f",seat,&time);
                ServiceSelect(F_WRLCK, seat,0);
                continue;
             case 2:
                printf(MSG_CONTSUBTIP);
                scanf("%s",seat);
                ServiceSelect(F_UNLCK, seat,0);
                continue;
             case 3:
                printf("请输入查询的座位号:");
                scanf("%s",seat);
                ServiceSelect(F_RDLCK, seat,1);
                continue;
             case 4:
                n=-1;
                printf("推出系统成功\n");
                break;
            default:
                printf("请输入有效数字!\n");
        }
    }
    
    return 0;
}
void ServiceSelect(int type,char* seat,int is_inq)
{
    struct flock lock;
    int fd;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    
    fd = open(seat, O_RDWR|O_CREAT,0666);
    if(fd < 0)
    {
        perror("图书馆座位订阅系统打开失败\n!");
        exit(1);
    }
    lock.l_type = type;
    if(is_inq==1)
    {
        fcntl(fd, F_GETLK,&lock);
        if(lock.l_type==F_WRLCK)
               printf("该座位也被其他学生预定\n");
        else printf("该座位没人预定");
        return;
    }
    if((fcntl(fd, F_SETLK,&lock))==0)
    {
        if (lock.l_type==F_RDLCK) {
        printf("\n 订阅成功! \n 离开时请退订座位\n");
            return ;
    }
    else if (lock.l_type == F_UNLCK)
    {
        if(getpid()==lock.l_pid)
             printf("退订成功！\n");
        else printf("你无法退订其他人的座位!\n");
    }
   
    }
    fcntl(fd, F_GETLK,&lock);
    if(lock.l_type==F_WRLCK)
        printf("该座位也被其他学生预定\n");
    return;
    
}
