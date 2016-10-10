#ifndef __TABLE_H__
#define __TABLE_H__

#include <stddef.h>

struct Table {
    int id;

    int fieldNum;

    // char **fieldRow;
    char **content;
    char contentArray[16][64];

    struct Table *next;
};
typedef struct Table TT;

/*
 * @paramaters
 *      char *field[] = {"App name", "id", "mode", "watching"};
 *   
 *      int tmpLen = sizeof(field)/sizeof(char *);
 * @return
 *      Table &tt;
 */
TT *tableInit(int len, char **field);

/*
 * @paramaters
 *      char *field2[] = {"koa.js", "1", "user", "yes"};
 *   
 *      int tmpLen = sizeof(field)/sizeof(char *);
 * @return
 *      Table &tt;
 */
void tablePush(TT *tt, int len, char **con);

/*
 * @return
 *      int tableLength;
 */
int tableLength(TT *tt);

/*
 * @return the pretty table!
 */
void printTable(TT *tt);



#endif