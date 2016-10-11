#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "table.h"

char *frame[] = {"─", "│", "┌", "┐", "└", "┘", "┬", "┤", "┴", "├", "┼"};
static int init_id = 0;
int idColor = 0;

// color format
char *gray_str = "\033[1;30m%s\033[0m";
char *gray_str_n = "\033[1;30m%s\033[0m\n";

char *light_blue_content_str    = "\033[1;36m %s \033[0m";
char *default_content_str       = "\033[m %s \033[0m";
char *yellow_content_str        = "\033[1;33m %s \033[0m";

// declaration
int getMaxSizeOfColumn(TT *tt, int index);
char* strWithPadding(int padding, char* color);


TT *tableInit(int len, char **field, int id)
{
    if (id) {
        idColor = 1;
    }
    
    TT *table = (TT*)malloc(sizeof(TT));
    table->id = init_id+1;
    
    table->content = field;

    int i;
    for (i = 0; i < len; i++) {
        strcpy(table->contentArray[i], field[i]);
    }
    table->fieldNum = len;

    table->next = NULL;

    return table;
}

void tablePush(TT *tt, int len, char **con) {
    TT *p, *cur;

    p = tt;

    while (p->next){
        p = p->next;
    }

    cur = (TT*)malloc(sizeof(TT));

    int i;
    for (i = 0; i < len; i++) {
        strcpy(cur->contentArray[i], con[i]);
    }
    
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
        i++;
        p=p->next;
    }

    return i;
}

void printTable(TT *tt) {
    TT *p = tt;
    
    int fieldNum = p->fieldNum;

    /* ****************************************************************************
	 * Fist frame boundary of row
	 * ****************************************************************************/
    int i;

    printf(gray_str, frame[2]);                         // ┌ ┌────
    for (i = 0; i < fieldNum; i++){
        int j;

		int size = getMaxSizeOfColumn(tt, i);
		
		for (j = 0; j < size + 2; j++) {
            printf(gray_str, frame[0]);                 // ─ ──────
		}

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

			int size = getMaxSizeOfColumn(tt, i);
            // printf("%d ", size);
			char *str;
            if (i == 0 && idColor) {
                str = strWithPadding(size, yellow_content_str);
            }else {
                str = strWithPadding(size, contentStr);
            }
            printf(str, p->contentArray[i]);             // ...

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

			int size = getMaxSizeOfColumn(tt, i);

			for (j = 0; j < size + 2; j++) {
				printf(gray_str, frame[0]);                 // ─ ──────
			}

			if (p->fieldNum - 1 > i)
			printf(gray_str, frameT);                     // ┬ ──┬───
		}
        printf(gray_str_n, frameE);

		/* ****************************************************************************/

        //next Node
        p = p->next;
    }
}


int getMaxSizeOfColumn(TT *tt, int index) {
	TT *p = tt;

	int maxSize = 0;

	while(p) {
		int j = 0;
		while(p->contentArray[index][j] != '\0') {
            j++;
        }
        // printf("%d ", j);
		
		if (j > maxSize) {
			maxSize = j;
		}
		p = p->next;
	}

	return maxSize;
}

char* strWithPadding(int padding, char* color) {
	char *str;
	char tmp[64];
	char tmp2[64];

	sprintf(tmp, "%%-%ds", padding);
	
	if (color) 
		sprintf(tmp2, color, tmp);

	str = tmp2;

	return str;
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