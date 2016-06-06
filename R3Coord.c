#include "R3Coord.h"

const double ERROR = 0.0000001;
int Igual(double a, double b) { 
    if (fabs(a - b) < ERROR)
    	return 1;
    return 0;
}

void initR3Coord(R3Coord *p, double x, double y, double z) {
	(*p).x = x;
	(*p).y = y;
	(*p).z = z;
}

double distanceBetweenTwoPoints(R3Coord p1, R3Coord p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
}

void printR3Coordinate(R3Coord p) {
	printf("(%.2lf, %.2lf, %.2lf)\n", p.x, p.y, p.z);
}

int equalR3Coord(R3Coord a, R3Coord b) {
	if (Igual(a.x, b.x) == 1 && Igual(a.y, b.y) == 1 && Igual(a.z, b.z) == 1)
		return 1;
	return 0;
}