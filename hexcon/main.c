#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hexcon.h"
#include "../table/table.h"

int INDEX = 0;

int main(int argc, char* argv[]) {

    char *field[] = {"id", "Decimal", "hexa", "Octal", "Binary", "!"};
    int fieldLen = sizeof(field)/sizeof(char *);

    TT *table = tableInit(fieldLen, field, 1);

    int arg = strcmp(argv[1], "-x");
    if (arg == 0) {
        printf("\033[0;32;34m[Hexa]\033[0m\033[1;34m Now, Input number in hexadecimal mode. \033[0m \n");
        
        int argI;
        for (argI = 2; argI < argc; argI++) {
            sprintf(argv[argI], "%d", htod(argv[argI]));
        }
    } else {
        printf("\033[0;33m[Decimal]\033[0m\033[1;33m Now, Input number in Decimal mode. \033[0m \n");

    }

        int i = 1;
        if (arg == 0) {
            i++;
        }
        for (; i < argc; i++) {
            char tmpStr[16];
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
        }
        
        printTable(table);

    return 0;
}