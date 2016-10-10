#include <stdio.h>
// #include <string.h>
// #include <stdarg.h>
#include <stdlib.h>
#include "table.h"

char *frame[] = {"─", "│", "┌", "┐", "└", "┘", "┬", "┤", "┴", "├", "┼"};
static int init_id = 0;

char *gray_str = "\033[1;30m%s\033[0m";
char *gray_str_n = "\033[1;30m%s\033[0m\n";

char *light_blue_content_str = "\033[1;36m %s \033[0m";
char *default_content_str = "\033[m %s \033[0m";


int getMaxSize(int len, char **con);


TT *tableInit(int len, char **field)
{
    TT *table = (TT*)malloc(sizeof(TT));
    table->id = init_id+1;
    
    table->fieldRow = field;
    table->content = field;
    table->fieldNum = len;

    table->next = NULL;

    // // unsigned long len = sizeof(table.row)/sizeof(char *);
    // printf("length of array: %d \n", len);

    // printf("%s \n", table->fieldRow[0]);

    // int tmp = getMaxSize(len, field);
    // printf("%d \n", tmp);
    
    return table;
}

void tablePush(TT *tt, int len, char **con) {
    TT *p, *cur;

    p = tt;

    while (p->next){

        // printf("===%d \n", p->id);
        // printf("===%s \n", p->content[0]);
        // printf("%x \n", p->next);

        p = p->next;
    }

    cur = (TT*)malloc(sizeof(TT));

    cur->content = con;
    cur->fieldNum = len;

    cur->next = NULL;
    p->next = cur;

}

int tableLength(TT *tt) {
    int i = 0;
    TT *p;

    p = tt;

    while(p) {
        // printf("---%d \n", i);
        // printf("---%d \n", p->id);
        // printf("---%s \n", p->content[0]);
        i++;
        p=p->next;
    }

    return i;
}

void printTable(TT *tt) {
    TT *p = tt;
    
    int fieldNum = p->fieldNum;
    int rowLength = getMaxSize(fieldNum, tt->content);

    int totalWidth = fieldNum + rowLength;
    // printf("%d \n", totalWidth);

    /* ****************************************************************************
	 * Fist frame boundary of row
	 * ****************************************************************************/
    int i;

    printf(gray_str, frame[2]);                         // ┌ ┌────
    for (i = 0; i < fieldNum; i++){
        int j = 0;
        while(p->content[i][j] != '\0') {
            printf(gray_str, frame[0]);                 // ─ ──────
            j++;
        }
        printf(gray_str, frame[0]);
        printf(gray_str, frame[0]);

        if (fieldNum - 1 > i)
        printf(gray_str, frame[6]);                     // ┬ ──┬───
    }
    printf(gray_str_n, frame[3]);                       // ┐ ─────┐
    
	char *contentStr = light_blue_content_str;
    while(p) {
        /* ****************************************************************************
		* Content Line
		* ****************************************************************************/
        printf(gray_str, frame[1]);                         // │ │ ... │
        for (i = 0; i < p->fieldNum; i++){
            printf(contentStr, p->content[i]);             // ...

            if (p->fieldNum - 1 > i)
            printf(gray_str, frame[1]);                     // │ ... │ ...
        }
        printf(gray_str_n, frame[1]);                       // │ ... │
		contentStr = default_content_str;

        /* ****************************************************************************
		* Last frame boundary of row
		* ****************************************************************************/
		char *frameT = frame[10];
		char *frameA = frame[9];
		char *frameE = frame[7];
		if (p->next == NULL) {
			frameT = frame[8];
			frameA = frame[4];
			frameE = frame[5];
		}
        
		printf(gray_str, frameA);
		for (i = 0; i < p->fieldNum; i++){
			int j = 0;
			while(p->content[i][j] != '\0') {
				printf(gray_str, frame[0]);                 // ─ ──────
				j++;
			}
			printf(gray_str, frame[0]);
			printf(gray_str, frame[0]);

			if (p->fieldNum - 1 > i)
			printf(gray_str, frameT);                     // ┬ ──┬───
		}
        printf(gray_str_n, frameE);

		/* ****************************************************************************/

        //next Node
        p = p->next;
    }

   


}

int getMaxSize(int len, char **con) {
    int size = 0;

    int i;
    for (i = 0; i < len; i++) {
        int j = 0;

        while(con[i][j] != '\0') {
            j++;
        }

        size += j;
    }

    return size;
}

int getMaxSizeOfColumn(TT *tt, int index) {
	TT *p = tt;

	int maxSize = 0;

	while(p) {
		p->content[index]
	}
}


// void tableInit(char *field, ...)
// {
//     va_list argp;
//     int argno = 0;
//     char *paramater;

//     va_start(argp, field);

//     while(1)
//     {
//         paramater = va_arg(argp, char *);
//         printf("?paramater #%d is: %s \n", paramater, paramater);
//         if (strcmp(paramater, "/0") == 0)
//             break;

//         printf("paramater #%d is: %s \n", argno, paramater);
//         argno++;
//     }
//     va_end(argp);
// }