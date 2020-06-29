#ifndef __ENCRYPT_H
#define __ENCRYPT_H

#include "Hotel.h"

#define MY_TEXT_FILE "myTextFile.txt"
#define MY_BINARY_FILE "myBinaryFile.bin"

void encryptFunction(void *, int numOfBytes);
void castRandomNumberAndCreateTxtFile();
void swapBits(unsigned char * varTemp, int indexBit1);
void XORencryption(unsigned char * varTemp);
void shiftRight(unsigned char * varTemp, int indexBit);
void shiftLeft(unsigned char * varTemp, int indexBit);
void decryptionFunction(void * variable, int varNumOfBytes, char *txt);
void decryptEntireHotel(Hotel * h, char *binaryFileName, char *txtFileName);
void encryptEntireHotel(Hotel h, char *binaryFileName, char *txtFileName);


#endif // !__ENCRYPT_H