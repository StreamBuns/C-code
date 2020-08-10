//
//  main.c
//  Ex6_5
//
//  Created by 赵桐 on 2020/5/29.
//  Copyright © 2020 赵桐. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#define MAXARRAY_WORD 1024
#define MAXLENG_WORD 20
int comparefuncint(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int i=0;
    char *item;
    char wordArray[MAXARRAY_WORD][MAXLENG_WORD];
    char word[MAXLENG_WORD];
    clock_t start,finish;
    FILE * file;
    file = fopen("word.txt", "r");
    if(file==NULL)
    {
        printf("打开文件出错\n");
    }
    while(fscanf(file, "%s",word)!=EOF)
    {
                printf("word:%s\n",word);
                strcpy(wordArray[i++], word);
    }
    qsort(wordArray, i-1, sizeof(wordArray[0]), comparefuncint);
    printf("请输入任意字符进行查找:\n");
    scanf("%s",word);
    start = clock();
    item = bsearch(&word, wordArray, i-1, sizeof(wordArray[0]), comparefuncint);
    finish = clock();
    if( item != NULL )
    {
       printf("单词集中有 %s，bsearch耗时%f\n", word,(double)(finish-start)/CLOCKS_PER_SEC);
    }
    else
    {
        printf("%s 不在单词集中，bsearch耗时%f\n", word,(double)(finish-start)/CLOCKS_PER_SEC);
    }
    fclose(file);
    return 0;
}
