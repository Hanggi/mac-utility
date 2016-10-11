#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hexcon.h"
#include "../table/table.h"

int INDEX = 0;

int main(int argc, char* argv[]) {

    // if (argc == 2) {
        char *field[] = {"id", "Decimal", "hexa", "Octal", "Binary", "!"};
        int fieldLen = sizeof(field)/sizeof(char *);

        TT *table = tableInit(fieldLen, field);
        
        int i;
        for (i = 1; i < argc; i ++) {
            // char *field[] = {"NaN", "NaN", "NaN", "NaN"};

            char *tmpStr;
            sprintf(tmpStr, "%d", ++INDEX);
            field[0] = tmpStr;

            field[1] = argv[i];

            char *p2 = dtoh(argv[i]);
            field[2] = p2;

            char *p3 = dtoo(argv[i]);
            field[3] = p3;

            char *p4 = dtob(argv[i]);
            field[4] = p4;
            tablePush(table, fieldLen, field);
            
        // printf("========== \n");
            free(p2);
            free(p3);
            free(p4);
            // free(fieldT);

        }

        
        printTable(table);

    // }

   

    return 0;
}