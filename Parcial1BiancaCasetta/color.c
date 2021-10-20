#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"
#include "input.h"
#include "bicicleta.h"
#include "servicio.h"
#include "tipo.h"
#include "color.h"
#include "fecha.h"

int cargarDescripcionColor(eColor colores[], int tamColor, int idColor, char nombreColor[])
{
    int error=-1;

    if(colores!=NULL && tamColor>0 && nombreColor!=NULL)
    {
        for(int i=0; i<tamColor; i++)
        {
            if(colores[i].id==idColor)
            {
                strcpy(nombreColor, colores[i].nombreColor);
            }
        }
        error=0;
    }
    return error;
}

int mostrarColores(eColor colores[], int tamColor)
{
    int error=-1;

    if(colores!=NULL && tamColor>0)
    {
        printf("\n");
        printf("          COLORES         \n");
        printf("--------------------------\n");
        printf(" ID |     DESCRIPCION     \n");
        printf("--------------------------\n");
        for(int i=0; i<tamColor; i++)
        {
            printf("%-5d%-21s\n", colores[i].id, colores[i].nombreColor);
        }
        printf("\n");

        error=0;
    }

    return error;
}
