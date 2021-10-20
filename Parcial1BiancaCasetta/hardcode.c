#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bicicleta.h"
#include "hardcode.h"

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

