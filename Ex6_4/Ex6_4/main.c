//
//  main.c
//  Ex6_4
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

void lock_set(int fd,int type);
int main(int argc, const char * argv[]) {
    // insert code here...
           int fd;
    fd=open("/mnt/usb", O_RDWR|O_CREAT|O_APPEND,0666);
    if(fd<0)
    {
        perror("文件打开/创建出错");
        exit(1);
    }
    lock_set(fd, F_WRLCK);
    lock_set(fd, F_UNLCK);

    return 0;
}
void lock_set(int fd,int type)
{
    struct flock lock;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    char buf[]="usb作为u盘设备文件";
    lock.l_type = type;
    if((fcntl(fd, F_SETLK,&lock))==0)
    {
        if (lock.l_type == F_WRLCK)
        {
            printf("文件加上了写入锁并写入了字符串：%s\n",buf);
            write(fd, buf, sizeof(buf));
            return;
        }
        else if(lock.l_type == F_UNLCK)
        {
            printf("文件释放了写入锁\n");
            return;
        }
    }
}
