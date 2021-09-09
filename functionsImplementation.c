#include "../STD-TYPES.h"
#include "functionsDeclartions.h"
#include <stdio.h>
#include <stdlib.h>
#include <Math.h>

extern u8 * numberOfTrips;

void generateRandomPoints (point * randomPointsArray)
{
	for(u8 iterator=0;iterator< (*numberOfTrips);iterator++)
	{
	
		
		randomPointsArray[iterator].x_axis=(rand()%(upperRange-lowerRange+1))+lowerRange;
		randomPointsArray[iterator].y_axis=(rand()%(upperRange-lowerRange+1))+lowerRange;
	}

		
	
	
	
	
}

void printRandomPoints (point * randomPointsArray)
{
	for(u8 iterator=0;iterator< (*numberOfTrips);iterator++)
	{
	printf("trip number%d location=(%d,%d)\n",iterator+1,randomPointsArray[iterator].x_axis,randomPointsArray[iterator].y_axis);
	}
	
	
	
	
}

void sortingPoints (pointWithDistance * sortedArray)
{
	
	 // arrange elemenets descending according to their distance from destinationPoint by bubbling sort techniuqe
	for (u8 iterator=0;iterator<(*numberOfTrips-1);iterator++)
	{
		for(u8 iterator=0;iterator<(*numberOfTrips-1);iterator++)
		{
			
			if(sortedArray[iterator].distance<sortedArray[iterator+1].distance)
			{
				// swapping x_axis coordinates using xor techniuqe
				sortedArray[iterator].p.x_axis   ^= sortedArray[iterator+1].p.x_axis;
				sortedArray[iterator+1].p.x_axis ^= sortedArray[iterator].p.x_axis;
				sortedArray[iterator].p.x_axis ^=sortedArray[iterator+1].p.x_axis;
				// swapping y_axis coordinates using xor techniuqe
				sortedArray[iterator].p.y_axis   ^= sortedArray[iterator+1].p.y_axis;
				sortedArray[iterator+1].p.y_axis ^= sortedArray[iterator].p.y_axis;
				sortedArray[iterator].p.y_axis ^=sortedArray[iterator+1].p.y_axis;				
				// swapping distance coordinates using xor techniuqe
				sortedArray[iterator].distance   ^= sortedArray[iterator+1].distance;
				sortedArray[iterator+1].distance ^= sortedArray[iterator].distance;
				sortedArray[iterator].distance ^=sortedArray[iterator+1].distance;				
			}
			
		}
	}
	
	
}

void printRandomPointsWithDistance (pointWithDistance * randomPointsArray)
{
	for(u8 iterator=0;iterator< (*numberOfTrips);iterator++)
	{
	printf("trip number%d location=(%d,%d)\n",iterator+1,randomPointsArray[iterator].p.x_axis,randomPointsArray[iterator].p.y_axis);
	}
	
	
	
	
}

void copyArray (pointWithDistance * destinationArray,point * currentArray)
{
	
    for(u8 iterator=0;iterator< (*numberOfTrips);iterator++)
	{
		destinationArray[iterator].p.x_axis= currentArray[iterator].x_axis;
		destinationArray[iterator].p.y_axis= currentArray[iterator].y_axis;
	}
		
	
	
}

void settingDistance(pointWithDistance * toBeSortedArray,point destinationPoint )
{
	for(u8 iterator=0;iterator< (*numberOfTrips);iterator++)
	{
		toBeSortedArray[iterator].distance=abs(toBeSortedArray[iterator].p.x_axis - destinationPoint.x_axis)+abs(toBeSortedArray[iterator].p.y_axis - destinationPoint.y_axis);
		
		
	}	
}

void printDirections( const point * destination ,const  point * current)
{
	

    
	if(((destination->x_axis-current->x_axis)<0))
	{
		printf("please move %c for %d KM then ",left_Arrow,abs((destination->x_axis-current->x_axis)));
		
	}
	else if ((destination->x_axis-current->x_axis)>0)
	{
		
		printf("please move %c for %d KM then ",right_Arrow,(destination->x_axis-current->x_axis));

	}
	
	
	if((destination->y_axis-current->y_axis)<0)
	{
				

		printf("please move %c for %d KM",down_Arrow,abs(destination->y_axis-current->y_axis));
		
		
	}
	else if (((destination->y_axis-current->y_axis)>0))
	{
		printf("please move %c for %d KM",up_Arrow,destination->y_axis-current->y_axis);

	}
	if(!(destination->x_axis-current->x_axis) && !(destination->y_axis-current->y_axis))
	{
		printf("you have reached ^-^");
	}
	


	
	
	
	
}

