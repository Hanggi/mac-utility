#include <stdio.h>
#include <stdlib.h>
#include "table.h"

#include <string.h>

int main(int argc, char* argv[]) {

    char *field[] = {"App name", "id", "mode", "watching"};
    int tmpLen = sizeof(field)/sizeof(char *);

    TT *table = tableInit(tmpLen, field);

    char *field2[] = {"koa.js", "1", "user", "yes"};
    tablePush(table, tmpLen, field2);

    char *field3[] = {"aa.js", "23", "kernal", "noooo"};
    tablePush(table, tmpLen, field3);

    printTable(table);
}
