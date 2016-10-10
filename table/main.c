#include <stdio.h>
#include <stdlib.h>
#include "table.h"

#include <string.h>

int main(int argc, char* argv[]) {

    // char *frame[] = {"─", "│", "┌", "┐", "└", "┘", "┬", "┴", "┼"};
    // char *frame2 = "─│┌┐└┘┬┴┼";

    char *field[] = {"App name", "id", "mode", "watching"};
    int tmpLen = sizeof(field)/sizeof(char *);

    // printf("l : %lu \n", sizeof(field));
    // printf("l : %lu \n", sizeof(char *));
    // tableInit("tt", "def", "123", "/0");
    TT *table = tableInit(tmpLen, field);
    
    char *field2[] = {"koa.js", "1", "user", "yes"};
    tablePush(table, tmpLen, field2);

    tablePush(table, tmpLen, field2);    

printf( "\033[m 输出默认字符 \033[0m\n" );

printf( "\033[0;32;31m 输出红色字符 \033[0m\n" );
printf( "\033[1;31m 输出亮红字符 \033[0m\n" );

printf( "\033[1;30m 输出灰色字符 \033[0m\n" );
printf( "\033[0;37m 输出亮灰字符 \033[0m\n" );

printf( "\033[0;32;32m 输出绿色字符 \033[0m\n" );
printf( "\033[1;32m 输出亮绿字符 \033[0m\n" );

printf( "\033[0;32;34m 输出蓝色字符 \033[0m\n" );
printf( "\033[1;34m 输出亮蓝字符 \033[0m\n" );

printf( "\033[0;36m 输出青色字符 \033[0m\n" );
printf( "\033[1;36m 输出亮青字符 \033[0m\n" );

printf( "\033[0;35m 输出粉色字符 \033[0m\n" );
printf( "\033[1;35m 输出亮粉字符 \033[0m\n" );

printf( "\033[0;33m 输出褐色字符 \033[0m\n" );
printf( "\033[1;33m 输出黄色字符 \033[0m\n" );

printf( "\033[1;37m 输出白色字符 \033[0m\n" );

//\033[1;30m
    // char *dd = "%d";
    // char *vv = strcat(dd, "\n");
    // printf("%s \n", vv);

    // int ll = tableLength(table);
    // printf("%d \n", ll);

    printTable(table);
    
    // int t = atoi(argv[1]);
    // printf("%d \n", t);
    // printf("%s \n", frame[t]);
}