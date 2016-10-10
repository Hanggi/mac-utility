#include <stdio.h>

struct Table {
    int id;

    int fieldNum;

    char **fieldRow;
    char **content;

    struct Table *next;
};
typedef struct Table TT;


TT *tableInit(int len, char **field);

void tablePush(TT *tt, int len, char **con);

int tableLength(TT *tt);

void printTable(TT *tt);
