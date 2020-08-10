//
//  main.c
//  1-1a
//
//  Created by 赵桐 on 2020/5/11.
//  Copyright © 2020 赵桐. All rights reserved.
//

#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
        int i,rfd,wfd,len=0,fd_in;
        char str[32];
        int flag,stdinflag;
        fd_set read_fd;
        struct timeval net_timer;

        mkfifo("fifo1",0644);
        mkfifo("fifo2",0644);

        wfd=open("fifo1",O_WRONLY);
        rfd=open("fifo2",O_RDONLY);
        printf("rfd=%d,wfd=%d",rfd,wfd);
        if(rfd<=0||wfd<=0)
                exit(1);
        printf("这是A的终端\n");
        while(1)
        {
                FD_ZERO(&read_fd);
                FD_SET(rfd,&read_fd);
                FD_SET(fileno(stdin),&read_fd);
                net_timer.tv_usec=0;
                net_timer.tv_usec=0;
                memset(str,0,sizeof(str));
                if((i=select(rfd+1,&read_fd,NULL,NULL,&net_timer))<=0)
                {
                    continue;
                }
                if(FD_ISSET(rfd,&read_fd))
                {
                    strcpy(str, "");
                    printf("-----------------------\n");
                    read(rfd, str, sizeof(str));
                    printf("张三:%s\n",str);
                    if (strcmp(str, "")) {
                        break;
                    }
                }
            if (FD_ISSET(fileno(stdin),&read_fd))
            {
                printf("-----------------------\n");
                fgets(str, sizeof(str), stdin);
                len=write(wfd,str,strlen(str));
            }
        }
    close(rfd);
    close(wfd);
}
