#pragma warning (disable: 4996)
#include "Encrypt.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Room.h"
#include "Hotel.h"


void encryptFunction(void * variable, int varNumOfBytes)
{
	int x = 0, i;	
	FILE * f = fopen(MY_TEXT_FILE, "r");
	fscanf(f, "%d", &x);
	
	for (i = 0; i < varNumOfBytes; i++)
	{
		unsigned char * varTemp = (unsigned char *)variable + i;
		swapBits(varTemp, x);
		XORencryption(varTemp);
		shiftRight(varTemp, x);
	}
	fclose(f);
}

void castRandomNumberAndCreateTxtFile()
{
	int random;
	random = rand() % 8;
	FILE * f = fopen(MY_TEXT_FILE, "w");
	if (f == NULL)
	{
		printf("\nFailed opening the file. Exiting!\n");
		exit(1);
		return;
	}

	fprintf(f, "%d", random);
	printf("TXT File has been successfully created!\n\n");

	fclose(f);

}

void swapBits(unsigned char * varTemp, int indexBit1)
{
	int indexBit2 = 0, bit1 = 0, bit2 = 0;
	if (indexBit1 != 7)
	{
		indexBit2 = indexBit1 + 1;
	}
	bit1 = getBitFromRight(*varTemp, indexBit1);
	bit2 = getBitFromRight(*varTemp, indexBit2);
	setBitFromRight(varTemp, indexBit1, bit2);
	setBitFromRight(varTemp, indexBit2, bit1);
	
}

void XORencryption(unsigned char * varTemp)
{
	*varTemp ^= 255;
}

void shiftRight(unsigned char * varTemp, int indexBit)
{
	int i;
	unsigned char bit;
	for (i = 0; i < indexBit; i++)
	{
		bit = getBitFromRight(*varTemp, 0);
		*varTemp = *varTemp >> 1;
		bit = bit << 7;
		*varTemp = *varTemp | bit;
	}
}

void shiftLeft(unsigned char * varTemp, int indexBit)
{
	int i;
	unsigned char bit;
	for (i = 0; i < indexBit; i++)
	{
		bit = getBitFromRight(*varTemp, 7);
		*varTemp = *varTemp << 1;
		*varTemp = *varTemp | bit;
	}
}

void decryptionFunction(void * variable, int varNumOfBytes, char * txtFileName)
{
	int x = 0, i;
	FILE * f = fopen(txtFileName, "r");
	fscanf(f, "%d", &x);

	for (i = 0; i < varNumOfBytes; i++)
	{
		unsigned char * varTemp = (unsigned char *)variable + i;
		shiftLeft(varTemp, x);
		XORencryption(varTemp);
		swapBits(varTemp, x);
	}
	fclose(f);

}

void encryptEntireHotel(Hotel h, char *binaryFileName, char *txtFileName)
{
	int i, j, x;
	int floors = h.numOfFloors;
	int roomsInFloor = h.numOfRoomsInFloor;
	FILE *textFile = fopen(txtFileName, "r");
	fscanf(textFile, "%d", &x);
	fclose(textFile);

	FILE *binaryFile = fopen(binaryFileName, "wb");

	encryptFunction(&(h.numOfFloors), sizeof(int));
	fwrite(&h.numOfFloors, sizeof(int), 1, binaryFile);
	encryptFunction(&(h.numOfRoomsInFloor), sizeof(int));
	fwrite(&h.numOfRoomsInFloor, sizeof(int), 1, binaryFile);

	for (i = 0; i < floors; i++)
	{
		for (j = 0; j < roomsInFloor; j++)
		{
			encryptFunction(&(h.allRooms[i][j]), sizeof(Room));
			fwrite(&h.allRooms[i][j], sizeof(Room), 1, binaryFile);
		}
	}

	printf("Hotel encrypted!");
	fclose(binaryFile);

}

void decryptEntireHotel(Hotel * h, char *binaryFileName, char *txtFileName)
{
	int i, j;
	FILE *binaryFile = fopen(binaryFileName, "rb");

	fread(&(h->numOfFloors), sizeof(int), 1, binaryFile);
	decryptionFunction(&(h->numOfFloors), sizeof(int), txtFileName);
	fread(&(h->numOfRoomsInFloor), sizeof(int), 1, binaryFile);
	decryptionFunction(&(h->numOfRoomsInFloor), sizeof(int), txtFileName);

	createHotel(h, h->numOfFloors, h->numOfRoomsInFloor);

	for (i = 0; i < h->numOfFloors; i++)
	{
		for (j = 0; j < h->numOfRoomsInFloor; j++)
		{
			fread(&(h->allRooms[i][j]), sizeof(Room), 1, binaryFile);
			decryptionFunction(&(h->allRooms[i][j]), sizeof(Room), txtFileName);
		}
	}
	printf("Hotel decrypted!");
	fclose(binaryFile);

}
