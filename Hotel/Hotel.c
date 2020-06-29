#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "Hotel.h"



void createHotel(Hotel * h, int floors, int rooms)
{
	h->numOfFloors = floors;
	h->numOfRoomsInFloor = rooms;
	Room ** roomsMatrix = (Room**)calloc(floors, sizeof(Room*));

	if (!roomsMatrix)
	{
		printf("ERROR! Out of memory");
		exit(1);
	}

	int i,j;
	for (i = 0; i < floors; i++)
	{
		roomsMatrix[i] = (Room*)calloc(rooms, sizeof(Room));
		for (j = 0; j < rooms; j++)
			GenerateRoomInfo(&roomsMatrix[i][j]);
	}

	h->allRooms = roomsMatrix;
}

void showHotelStatus(Hotel * h)
{
	int i, j;
	printf("|Hotel details|:\n\n");
	for (i = h->numOfFloors - 1; i >= 0; i--)
	{
		printf("Floor number %d\n", (i + 1));
		printf("---------------\n");
		for (j = 0; j < h->numOfRoomsInFloor; j++)
		{
			printf("\nRoom number %d \n", (i + 1) * 100 + (j + 1));
			printRoomDetails(h->allRooms[i][j]);
		}
		printf("\n");
	}
}

int checkIfRoomExists(int room, Hotel * h)
{
	int floor = room / 100 - 1;
	int roomNumOnFloor = room % 100 - 1;
	if (floor < 0 || floor >= h->numOfFloors || roomNumOnFloor < 0 || roomNumOnFloor >= h->numOfRoomsInFloor)
	{
		printf("The room number entered is invalid, please try again:");
		return 0;
	}
	return 1;
}

Room getRoomForFeatureChecking(int roomNumber, Hotel h)
{
	int floor = roomNumber / 100 - 1;
	int roomItself = roomNumber % 100 - 1;
	return h.allRooms[floor][roomItself];
}

void allRoomsWithSameExistingFeature(Hotel h, int feature)
{
	printf("The available Rooms with the feature:\n");
	int i, j;
	for (i = 0; i < h.numOfFloors; i++)
	{
		for (j = 0; j < h.numOfRoomsInFloor; j++)
		{
			if (doesFeatureExistInRoom(h.allRooms[i][j], feature) == 1)
			{
				printf("{Room number %d} \n", (i + 1) * 100 + (j + 1));
				printRoomDetails(h.allRooms[i][j]);
			}
		}
	}
}

void variadicCheckAndPrint(int feature,Room * r,...)
{
	va_list allRooms;
	Room* currentRoom;
	int i=0, j=0;
    va_start(allRooms, r);
	currentRoom = r;
	while (currentRoom != NULL)
	{
		if (getBitFromRight(r->roomInfo, feature) == 1)
		{
			printf("\n{Room number %d} \n", (i + 1) * 100 + (j + 1));
			printRoomDetails(*r);
			j++;
		}
		currentRoom = va_arg(allRooms, Room *);
	}
	printf("\n");
 
       va_end(allRooms);

}

void freeHotel(Hotel * h) 
{
	int i;
	for (i = 0; i < h->numOfFloors; i++)
	{
		free(h->allRooms[i]);
	}
	free(h->allRooms);
}



