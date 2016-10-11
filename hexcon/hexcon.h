#ifndef __HEXCON_H__
#define __HEXCON_H__


/*
 * Decimal to Hexadecimal
 * @paramaters
 *      char *digit = "1002";
 * @return
 *      char *str; // 0x12A3DF
 */
char* dtoh(char* digit);

/* 
 * Decimal to Octal
 * @paramaters
 *      char *digit = "1002";
 * @return
 *      char *str; // 02316
 */
char* dtoo(char* digit);

/* 
 * Decimal to Binary
 * @paramaters
 *      char *digit = "1002";
 * @return
 *      char *str; // 1010010110
 */
char* dtob(char* digit);


int htod(char* digit);



#endif