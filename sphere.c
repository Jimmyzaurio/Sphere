/*
Autor: Jesus Saucedo Perez
Subject: Computer Graphics
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "list.h"
#include "R3Coord.h"

const double RADIO = 200;

int validation(int u, int v);
void createVLF(int u, int v, Node * list);
void debug(int u, int v, Node* vertexes);

int main(int argc, char* argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Must pass two arguments!\n");
		exit(1);
	}

	int u = atoi(argv[1]); // Sides of the polygon
	int v = atoi(argv[2]);

	// We're going to validate that it's possible to build that sphere
	if (!validation(u, v)) {
		printf("It is impossible to build a sphere with that parameters\n");
		exit(1);
	}
	
	double angle = 360.0/u;
	Node* vertexes = NULL;
	
	double x;
	double y;
	double z;
	int i;
	for (i = 0; i <= u; i++) { 
		x = RADIO * cos(i * (angle + 270) * M_PI / 180.0);
		y = RADIO * sin(i * (angle + 270) * M_PI/ 180.0);
		z = 0.0;

		if (Igual(x, 0))	x = 0.0;
		if (Igual(y, 0))	y = 0.0;
		if (Igual(z, 0))	z = 0.0;

		R3Coord ver;
		initR3Coord(&ver, x, y, z);
		if (findInList(vertexes, &ver) == 0)
			vertexes = append(vertexes, &ver);

		int j;
		for (j = 0; j <= v; j++) {
			double _x = x * sin(j * angle * M_PI / 180.0);
			z = x * cos(j * angle * M_PI/ 180.0);

			if (Igual(_x, 0))	_x = 0.0;
			if (Igual(z, 0))	z = 0.0;

			initR3Coord(&ver, _x, y, z);
			if (findInList(vertexes, &ver) == 0)
				vertexes = append(vertexes, &ver);
		}
	}
	//debug(u, v, vertexes);
	createVLF(u, v, vertexes);
	return 0;
}

int validation(int u, int v) {
	if (u >= 3 && v >= 2) return 1;
	return 0;
}

void createVLF(int u, int v, Node * list) {
	Node *imp = list;
	FILE *archivo = fopen("sphere.vlf", "w");

    fprintf(archivo, "Input\nu = %d v = %d\n", u, v);
	fprintf(archivo, "%s \t %8s \t %8s \t %8s\n", "Vertex", "v1", "v2", "v3");
	int conta = 0;
	for (; imp; imp = imp->next) {
		R3Coord ver = *(R3Coord*)imp->data;
		fprintf(archivo, "%d \t\t %8.2lf \t %8.2lf \t %8.2lf\n", conta++, ver.x, ver.y, ver.z);
	}
}

void debug(int u, int v, Node* vertexes) {
	Node* imp = vertexes;
	printf("Input\nu = %d v = %d\n", u, v);
	printf("%s \t %8s \t %8s \t %8s\n", "Vertex", "v1", "v2", "v3");
	int conta = 0;
	for (; imp; imp = imp->next) {
		R3Coord ver = *(R3Coord*)imp->data;
		printf("%d \t %8.2lf \t %8.2lf \t %8.2lf\n", conta++, ver.x, ver.y, ver.z);
	}	
}
