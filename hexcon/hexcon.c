#include <stdio.h>
#include <stdlib.h>
#include "hexcon.h"


char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

char* dtoh(char* digit) {
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
        reminder = num % 16;

        arr[i++] = reminder; 
        num = num / 16;
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

char* dtoo(char* digit) {
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
        reminder = num % 8;

        arr[i++] = reminder; 
        num = num / 8;
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

char* dtob(char* digit) {
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
        reminder = num % 2;

        arr[i++] = reminder; 
        num = num / 2;
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