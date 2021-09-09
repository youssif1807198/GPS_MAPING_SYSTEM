#include "../STD-TYPES.h"
#include <stdio.h>
#include <stdlib.h>
#include "functionsDeclartions.h"

u8 * numberOfTrips= NULL;

void main(void)
{
	//take position and destination points as input from user
	
	point positionPoint, destinationPoint;

	printf("*************************GPS MAPPING SYSTEM*************************\n");
	
	printf("********please enter your position in x and y coordinates********\nyour x-coordinante:");
	scanf("%d",&positionPoint.x_axis);
	printf("your y-coordinante:");
	scanf("%d",&positionPoint.y_axis);
	

	printf("********please enter your destination in x and y coordinates********\nyour x-coordinante:");
	scanf("%d",&(destinationPoint.x_axis));
	printf("your y-coordinante:");
    scanf("%d",&(destinationPoint.y_axis));
	

	numberOfTrips= (u8 *)malloc(sizeof(u8));
    printf("\nplease enter number of trips for today:");
	scanf("%d",numberOfTrips);

	
	point randomPointsArray[*numberOfTrips];
	pointWithDistance toBeSortedarray[*numberOfTrips];
	
	
	generateRandomPoints(randomPointsArray);
	//printing random points before sorting them
	printf("points before sorting:\n");
	printRandomPoints(randomPointsArray);
	
	
	copyArray(toBeSortedarray,randomPointsArray);
	settingDistance(toBeSortedarray,destinationPoint);
	sortingPoints(toBeSortedarray);
	//printing random points after sorting them
	printf("points after sorting:\n");	
	printRandomPointsWithDistance(toBeSortedarray);
	
	printf("Directions for trip (1): ");
	printDirections(&(toBeSortedarray[0].p),&positionPoint);
	
	for (u8 iterator =0;iterator<(*numberOfTrips-1);iterator++)
	{
			printf("\nDirections for trip (%d): ",iterator+2);

		printDirections(&(toBeSortedarray[iterator+1].p),&(toBeSortedarray[iterator].p));
	}
	
		printf("\nDirections for Last trip : ");
		printDirections(&destinationPoint,&(toBeSortedarray[*numberOfTrips-1].p));



	


	
	
	
	
}