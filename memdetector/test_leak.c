#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv)
{

    int *p;
    p = (int*)malloc(100);
    int *p2;
    p2 = (int*)malloc(100);
    int *p3;
    p3 = (int*)malloc(100);

    free(p2);


    printf("Program is exit!\n");

    return 0;
}
