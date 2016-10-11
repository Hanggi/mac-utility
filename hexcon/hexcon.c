#include <stdio.h>
#include <stdlib.h>
#include "hexcon.h"

char* dealDecimal(char* digit, int divider);
char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};


char* dtoh(char* digit) {
    char* res = dealDecimal(digit, 16);

    int ll = 0;
    while(res[ll] != '\0') {
        ll++;
    }

    int i;
    for (i = ll - 1; i >= 0; i--) {
        res[i+2] = res[i];
    }
    res[0] = '0';
    res[1] = 'x';

    return res;
}

char* dtoo(char* digit) {
    char* res = dealDecimal(digit, 8);

    int ll = 0;
    while(res[ll] != '\0') {
        ll++;
    }

    int i;
    for (i = ll - 1; i >= 0; i--) {
        res[i+1] = res[i];
    }
    res[0] = '0';

    return res;
}

char* dtob(char* digit) {
    char* res = dealDecimal(digit, 2);

    return res;
}

char* dealDecimal(char* digit, int divider) {
    int num = atoi(digit);
    if (num == 0) {
        printf("Please input valid number.");
        return "0";
    }
    // printf("%d \n", num);
    int arr[64];
    int reminder;

    int i = 0;
    while (num > 0) {
        reminder = num % divider;

        arr[i++] = reminder; 
        num = num / divider;
    }

    int charLength = i;
    int j = 0;
    char *res = malloc(sizeof(char) * charLength);
    for (i = i - 1; i >= 0; i--) {
        int t = arr[i];
        res[j] = hex[t];
        
        j++;
    }
    res[charLength] = '\0';

    return res;
}