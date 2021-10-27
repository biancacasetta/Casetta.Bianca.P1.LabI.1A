#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bicicleta.h"
#include "hardcode.h"
#include "trabajo.h"

char marcas[10][20] = {
		"Olmo",
		"Vairo",
		"Venzo",
		"Top Mega",
		"Raleigh",
		"Trinx",
		"Giant",
		"Canyon",
		"Trek",
		"Cannondale"
};

int idColores[10] = {5001, 5002, 5000, 5001, 5001, 5003, 5004, 5002, 5004, 5001};

char materiales[10] = {'C', 'C', 'A', 'C', 'A', 'A', 'A', 'C', 'C', 'A'};

int idTipos[10] = {1001, 1002, 1000, 1001, 1001, 1003, 1000, 1002, 1000, 1001};

int hardcodearBicicletas(eBicicleta bicicletas[], int tamBici, int cantidad, int* id)
{
	int contador=-1;

	if(bicicletas!=NULL && tamBici>0 && cantidad>=0 && cantidad<=tamBici && id!=NULL)
	{
		contador=0;
		for(int i=0; i<cantidad; i++)
		{
			bicicletas[i].id = *id;
			(*id)++;
			strcpy(bicicletas[i].marca, marcas[i]);
			bicicletas[i].idColor=idColores[i];
			bicicletas[i].idTipo=idTipos[i];
			bicicletas[i].material=materiales[i];
			bicicletas[i].isEmpty=0;
			contador++;
		}
	}
	return contador;
}

int idsBicicleta[15]={1,1,5,3,9,8,10,6,5,7,2,3,10,9,9};

int idsServicio[15]={20001,20002,20001,20000,20003,20003,20001,20000,20002,20003,20003,20001,20002,20000,20000};

eFecha fechas[15]={{27,12,1991},
                   {26,06,1996},
                   {22,02,2000},
                   {30,11,2001},
                   {03,12,2001},
                   {31,05,2000},
                   {12,10,1997},
                   {01,01,2003},
                   {10,01,2001},
                   {07,01,1995},
                   {13,01,1970},
                   {16,10,1964},
                   {27,03,1984},
                   {19,12,1976},
                   {20,8,2007}
                   };

int hardcodearTrabajos(eTrabajo trabajos[], int tamTrab, int cantidad, int* id)
{
    int contador=-1;

	if(trabajos!=NULL && tamTrab>0 && cantidad>=0 && cantidad<=tamTrab && id!=NULL)
	{
		contador=0;
		for(int i=0; i<cantidad; i++)
		{
			trabajos[i].id=*id;
			(*id)++;
            trabajos[i].idBicicleta=idsBicicleta[i];
			trabajos[i].idServicio=idsServicio[i];
			trabajos[i].fecha=fechas[i];
			trabajos[i].isEmpty=0;
			contador++;
		}
	}
	return contador;
}
