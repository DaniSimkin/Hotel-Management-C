#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include "Room.h"
#include "Hotel.h"
#include "menuScreen.h"
#include "RoomFeatureChoice.h"
#include "Encrypt.h"


void main(int  argc, char*  argv[]) {

	Hotel DaniHotel;
	srand((unsigned int)time(NULL));
	int roomsInHotel, FloorsInHotel;
	if (argc >2) 
	{
		printf("The program cannot run with the parameters sent.\nRun the program again with the .bin file with the saved hotel or without parameters at all.\n");
		system("pause");
		return;
	}
	else if (argc == 2) 
	{
		char* binaryFileLoad = argv[1];

		if (binaryFileLoad == NULL)
		{
			printf("File cannot be loaded, the program will now exit.\n");
			return;
		}

		decryptEntireHotel(&DaniHotel, binaryFileLoad, MY_TEXT_FILE);
		printf("Hotel loaded successfully! :\n");
	}
	else
	{
		do {
			printf("Please enter number of floors(1-9):");
			scanf("%d", &FloorsInHotel);
		} while (FloorsInHotel < 1 || FloorsInHotel > 9);
		do {
			printf("Please enter number of rooms in floor (1-99):");
			scanf("%d", &roomsInHotel);
		} while (roomsInHotel < 1 || roomsInHotel > 99);
		printf("The program will create a new hotel.\n");
		createHotel(&DaniHotel, FloorsInHotel, roomsInHotel);
		printf("Hotel created!\n\n");
		castRandomNumberAndCreateTxtFile();
	}

	int menuChoice, roomNumber;

	if (DaniHotel.numOfRoomsInFloor > 2)
	{
		printf("\nFirst of the three rooms with balcony feature details:\n");
		variadicCheckAndPrint(BALCONY_FEATURE,&DaniHotel.allRooms[0][0],&DaniHotel.allRooms[0][1],&DaniHotel.allRooms[0][2],NULL);
	}

	do
	{
		menuScreen();
		scanf("%d", &menuChoice);
		switch (menuChoice)
		{
		case 1:
			showHotelStatus(&DaniHotel);
			break;

		case 2:
			printf("Please enter a valid room number ");
			do {
				scanf("%d", &roomNumber);
			} while (checkIfRoomExists(roomNumber, &DaniHotel) != 1);

			if (doesFeatureExistInRoom(getRoomForFeatureChecking(roomNumber, DaniHotel), roomFeatureChoice()) == 1)
				printf("Feature Exists!\n");
			else
				printf("Feature does not exist\n");

			break;

		case 3:
			allRoomsWithSameExistingFeature(DaniHotel,allRoomsFeatureChoice());
			break;

		case 4:
			encryptEntireHotel(DaniHotel, MY_BINARY_FILE, MY_TEXT_FILE);
			break;

		case 5:
			decryptEntireHotel(&DaniHotel, MY_BINARY_FILE, MY_TEXT_FILE);
			break;

		case 0:
			printf("Goodbye\n");
			break;

		default:
			printf("invalid input");
			break;
		}
	} while (menuChoice != 0);
	
	freeHotel(&DaniHotel);
	system("pause");

}

