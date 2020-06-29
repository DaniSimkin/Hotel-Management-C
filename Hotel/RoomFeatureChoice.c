#pragma warning (disable: 4996)
#include "Hotel.h"
#include "Room.h"
#include <stdio.h>
#include <stdlib.h>

int roomFeatureChoice()
{
	int featureIndex;
	printf("\nWelcome to room features menu. See if a certain feature exists in room\n");
	printf("0 - Pool View\n");
	printf("1 - Balcony\n");
	printf("2 - Tea Pot\n");
	printf("3 - Free Wifi\n");
	printf("4 - Sofa\n");
	printf("5 - TV\n");
	printf("6 - Room Free\n");
	do
	{
		scanf("%d", &featureIndex);
		if (featureIndex < 0 || featureIndex > 6)
			printf("Please choose a valid option ");
	} while (featureIndex < 0 || featureIndex > 6);

	return featureIndex;
} 

int allRoomsFeatureChoice()
{
	int featureIndex;
	printf("\nWelcome to room features menu. Choose a feature to view all available rooms with same feature\n");
	printf("0 - Pool View\n");
	printf("1 - Balcony\n");
	printf("2 - Tea Pot\n");
	printf("3 - Free Wifi\n");
	printf("4 - Sofa\n");
	printf("5 - TV\n");
	printf("6 - Room Free\n");
	do
	{
		scanf("%d", &featureIndex);
		if (featureIndex < 0 || featureIndex > 6)
		printf("Please choose a valid option ");
	} while (featureIndex < 0 || featureIndex > 6);

	return featureIndex;
}
