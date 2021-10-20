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

int cargarDescripcionTipo(eTipo tipos[], int tamTipo, int idTipo, char descripcion[])
{
    int error=-1;

    if(tipos!=NULL && tamTipo>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamTipo; i++)
        {
            if(tipos[i].id==idTipo)
            {
                strcpy(descripcion, tipos[i].descripcion);
                error=0;
            }
        }
    }
    return error;
}

int mostrarTipos(eTipo tipos[], int tamTipo)
{
    int error=-1;

    if(tipos!=NULL && tamTipo>0)
    {
        printf("\n");
        printf("           TIPOS          \n");
        printf("--------------------------\n");
        printf(" ID |     DESCRIPCION     \n");
        printf("--------------------------\n");
        for(int i=0; i<tamTipo; i++)
        {
            printf("%-5d%-21s\n", tipos[i].id, tipos[i].descripcion);
        }
        printf("\n");

        error=0;
    }

    return error;
}
