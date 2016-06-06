#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct vertice {
	int index;
	double x,y,z;
};
typedef struct vertexList {
	struct vertice vertice_elem;
	struct vertexList *sig;
}*VertexList;

VertexList vacio() { 
	return NULL;
}
int esvacia(VertexList v) { 
	return v==NULL; 
}
VertexList resto(VertexList v) { 
	return v->sig; 
}

int estaEnLista(VertexList v, double x, double y, double z) {
	struct vertice aux_vertice;
	VertexList aux = v;
	double x2,y2,z2;

	while(!esvacia(aux)) {
		aux_vertice = aux->vertice_elem;

		x2 = aux_vertice.x;
		y2 = aux_vertice.y;
		z2 = aux_vertice.z;

		if( x==x2  && y==y2 && z==z2  ){
			return 1;
		}
		aux = (VertexList)resto(aux);
	}	
	return -1;
}

VertexList inserToVertexList(VertexList v, double x, double y, double z, int index) {
	VertexList aux = (VertexList) malloc(sizeof(struct vertexList));

	struct vertice aux_vertice;
	aux_vertice.index = index;
	aux_vertice.x = x;
	aux_vertice.y = y;
	aux_vertice.z = z;

	aux->vertice_elem = aux_vertice;
	aux->sig = v;
	return aux;
}

void implistaVertives(VertexList v) {
	if(!esvacia(v)){
		implistaVertives(resto(v));
		printf("    %d | %lf \t %lf \t %lf \n",v->vertice_elem.index,v->vertice_elem.x,v->vertice_elem.y,v->vertice_elem.z);
	}	
}

#define PI 3.14159265358979323846
int main(int argc, char * arrgv[] ){
	
	double v=atoi(arrgv[1]);//para XY
	double u=atoi(arrgv[2]);//para XZ
	
	double x=0;
	double x2=0;
	double y=0;
	double z=0;
	

	double centroEsferaX=0.0;
	double centroEsferaY=0.0;
	double centroEsferaZ=0.0;

	double radio=300;
   	double val = PI / 180.0;
   	
	printf("\nv=%lf - u=%lf",v,u);
	printf("\n\n\tCentro X=%lf Y=%lf Z=%lf radio=%lf\n\n",centroEsferaX,centroEsferaY,centroEsferaZ,radio);
	
	double inicio=0;//inicio de los angulos
	double inicioZ=0;


	int index=0;
	VertexList vl = vacio();


	for(inicio=0;inicio<=360;inicio+=180/v){
		x = (double)(radio)*cos((inicio+270)*val);
		y = (double)(radio)*sin((inicio+270)*val);
	   	z = 0;

			if((int)x==-0)
				x=0.0;
			if((int)y==-0)
				y=0.0;
			if((int)z==-0)
				z=0.0;

		
		printf("\nCoordenadas en:  X=%lf \t Y=%2.2lf \t Z=%2.2lf ", centroEsferaX+x,centroEsferaY+ y, centroEsferaZ+z);
		
		if(estaEnLista(vl,(double)(centroEsferaX+x),centroEsferaY+y,centroEsferaZ+z)==-1 ){
			printf("\t|vertice agregado|\n");
			vl = inserToVertexList(vl,centroEsferaX+x,centroEsferaY+y,centroEsferaZ+z,index++);
		}else{
			printf("\t|este vertice ya esta|\n");
		}

		for(inicioZ=0;inicioZ<=360;inicioZ+=180/u){
			x2 = x*sin(inicioZ*val);
		   	z  = x*cos(inicioZ*val);
		   	if((int)x2==-0)
				x2=0.0;
			if((int)z==-0)
				z=0.0;
			
			printf("\n\tX2=%2.2lf \t Y=%2.2lf \t Z=%2.2lf", centroEsferaX+x2, centroEsferaY+y, centroEsferaZ+z);	
			if(estaEnLista(vl,x2,centroEsferaY+y,centroEsferaZ+z)==-1 ){
				printf("\t\t|vertice agregado|");
				vl = inserToVertexList(vl,x2,centroEsferaY+y,centroEsferaZ+z,index++);
			}else{
				printf("\t\t|este vertice ya esta|");
			}
		}
		
		   	printf("\n");
	}
	
	printf("\n-------------------------------------\n\tLista de vertices\nIndex | \tx\t   y\t\t   z \n"); 
	implistaVertives(vl);
	printf("-------------------------------------\n\n");


	return 0;
}





