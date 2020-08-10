//
//  main.c
//  Ex8_5_1
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
    int r_num;
    int pipe_fd[2];
    FILE * fd;
    char buf_r[150],buf_w[150];
    if (pipe(pipe_fd)<0)
    {
        printf("创建管道失败");
        exit(1);
    }
    child = fork();
    if (child<0)
    {
        printf("创建子进程失败");
        exit(1);
    }
    else if (child==0)
    {
        close(pipe_fd[1]);
        while((r_num=read(pipe_fd[0], buf_r, sizeof(buf_r))>0))
        {
            printf("%s",buf_r);
            memset(buf_r, 0, sizeof(buf_r));
        }
        close(pipe_fd[0]);
        exit(0);
    }
    else
    {
        close(pipe_fd[0]);
        fd = fopen("readfile", "r");
        memset(buf_r, 0, sizeof(buf_r));
        while(fgets(buf_w, sizeof(buf_w), fd)!=NULL)
        {
            write(pipe_fd[1], buf_w, strlen(buf_w));
            memset(buf_r, 0, sizeof(buf_r));
        }
        close(pipe_fd[1]);
        waitpid(child, NULL, 0);
        exit(0);
        
    }
    return 0;
}
