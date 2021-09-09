#ifndef _FUNCTIONSDECLARTIONS_H_ 
#define _FUNCTIONSDECLARTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include "../STD-TYPES.h"
#define upperRange  100
#define lowerRange  -100

typedef struct point
{
	s8 x_axis;
	s8 y_axis;
	
}point;

typedef struct pointWithDistance
{
	point p;
	u16 distance; 
}pointWithDistance;

typedef enum arrows
{
	up_Arrow=24,
	down_Arrow=25,
	right_Arrow=26,
	left_Arrow=27,
	
	
}arrows;

void generateRandomPoints (point * randomPointsArray);
void printRandomPoints (point * randomPointsArray);
void sortingPoints (pointWithDistance * sortedArray);
void printRandomPointsWithDistance (pointWithDistance * randomPointsArray);
void settingDistance(pointWithDistance * toBeSortedArray,point destinationPoint );
void copyArray (pointWithDistance * destinationArray,point * currentArray);
void printDirections(const point * destination ,const point * current);








#endif