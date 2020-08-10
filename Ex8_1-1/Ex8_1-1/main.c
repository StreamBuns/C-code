//
//  main.c
//  Ex8_1-1
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

#define BUFSIZE 20
int main(int argc, const char * argv[]) {
    // insert code here...
//    int fd_ori,fd_aft;
    int fd_ori;
    char buf[BUFSIZE];
    int len;
    int totallen=0;
    //定义变量
    
//    if(argc<3){
//        printf("请输入正确的参数！\n");
//        exit(1);
//    }
//    fd_ori = open(argv[1], O_CREAT|O_RDONLY,0600);
//    fd_aft = open(argv[2], O_CREAT|O_TRUNC|O_WRONLY,0600);
//    if(fd_ori==-1||fd_aft==-1)
    fd_ori = open("./经济学张玉颍2018416429.tex", O_CREAT|O_RDONLY,0600);
    if(fd_ori==-1)
    {
        printf("打开文件出错！\n");
        exit(1);
    }
    //打开文件
    
    for(;;)
    {
    len=read(fd_ori, buf, BUFSIZE);
    if(len<0)
    {
        printf("读入文件出错！\n");
        exit(1);
    }
    else if(len>0)
    {
//        write(fd_aft, buf, strlen(buf));
        totallen+=len;
    }
    else if(len==0)break;
    }
    //读文件，写文件
    printf("文件字数：%d\n",totallen);
    return 0;
}
