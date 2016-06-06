#ifndef __R3COORD_H
#define __R3COORD_H

#include <stdio.h>
#include <math.h>
typedef struct R3Coord{
	double x;
	double y;
	double z;
}R3Coord;

int Igual(double a, double b);
void initR3Coord(R3Coord*,double, double, double);//Inicializa una coordenada en R3
double distanceBetweenTwoPoints(R3Coord, R3Coord);//Obtiene la distancia entre dos puntos
void printR3Coordinate(R3Coord);
int equalR3Coord(R3Coord, R3Coord);

#endif