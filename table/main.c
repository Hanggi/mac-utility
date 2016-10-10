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

    char *field3[] = {"aa.js", "23", "kernal", "noooo"};
    tablePush(table, tmpLen, field3);    

    // char *dd = "%d";
    // char *vv = strcat(dd, "\n");
    // printf("%s \n", vv);

    // int ll = tableLength(table);
    // printf("%d \n", ll);

    printTable(table);
    
    // int t = atoi(argv[1]);
    // printf("%d \n", t);
    // printf("%s \n", frame[t]);

    // strWithPadding(2);
}