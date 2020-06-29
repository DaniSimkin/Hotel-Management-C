#include <stdio.h>
#include <stdlib.h>
#include "Room.h"


void GenerateRoomInfo(Room *myRoom)
{
	int beds, random, i;
	beds = rand() % 4 + 1;
	myRoom->numOfBeds = beds;

	for (i = 0; i < ROOM_ITEM_DETAILS; i++)
	{
		random = rand() % 2;
		setBitFromRight(&myRoom->roomInfo, i, random);
		
	}
}

void printRoomDetails(Room myRoom)
{
	int i;
	printf("\nRoom details:\n");
	printf("\tNumber of beds - %d\n", myRoom.numOfBeds);
	for (i = 0; i < ROOM_ITEM_DETAILS; i++)
	{
		switch (i)
		{
		case 0:
			if (getBitFromRight(myRoom.roomInfo, i) == 1)
			{
				printf("\tRoom a has pool view\n");
			}
			else
			{
				printf("\tRoom does not have pool view\n");
			}

			break;

		case 1:
			if (getBitFromRight(myRoom.roomInfo, i) == 1)
			{
				printf("\tRoom has a balcony\n");
			}
			else
			{
				printf("\tRoom does not have a balcony\n");
			}
			break;

		case 2:
			if (getBitFromRight(myRoom.roomInfo, i) == 1)
			{
				printf("\tRoom has a tea pot\n");
			}
			else
			{
				printf("\tRoom does not have a tea pot\n");
			}
			break;

		case 3:
			if (getBitFromRight(myRoom.roomInfo, i) == 1)
			{
				printf("\tRoom has free wifi\n");
			}
			else
			{
				printf("\tRoom does not have free wifi\n");
			}
			break;

		case 4:
			if (getBitFromRight(myRoom.roomInfo, i) == 1)
			{
				printf("\tRoom has an opening sofa\n");
			}
			else
			{
				printf("\tRoom does not have an opening sofa\n");
			}
			break;

		case 5:
			if (getBitFromRight(myRoom.roomInfo, i) == 1)
			{
				printf("\tRoom has a TV\n");
			}
			else
			{
				printf("\tRoom does not have a TV\n");
			}
			break;

		case 6:
			if (getBitFromRight(myRoom.roomInfo, i) == 0)
			{
				printf("\tRoom is taken\n");
			}
			else
			{
				printf("\tRoom is available\n\n");
			}
			break;

		default:
			break;
		}
	}
}

void setBitFromRight(unsigned char *ch, int index, int value)
{
	unsigned char mask = 1; // 00000001
	mask <<= index;

	if (value == 1)
		*ch = *ch | mask;
	else
	{
		mask = ~mask;
		*ch = *ch & mask;
	}
}

int getBitFromRight(unsigned char ch, int index)
{
	unsigned char mask = 1; // 00000001
	mask = mask << index;

	if ((ch & mask) == 0)
		return 0;
	else
		return 1;
}

int doesFeatureExistInRoom(Room r, int indexFeature)
{
	return getBitFromRight(r.roomInfo, indexFeature);
}











