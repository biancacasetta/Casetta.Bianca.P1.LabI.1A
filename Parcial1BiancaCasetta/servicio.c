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

int cargarDescripcionServicio(eServicio servicios[], int tamServ, int idServicio, char descripcion[])
{
    int error=-1;

    if(servicios!=NULL && tamServ>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamServ; i++)
        {
            if(servicios[i].id==idServicio)
            {
                strcpy(descripcion, servicios[i].descripcion);
            }
        }
        error=0;
    }
    return error;
}

int mostrarServicios(eServicio servicios[], int tamServ)
{
    int error=-1;

    if(servicios!=NULL && tamServ>0)
    {
        printf("\n");
        printf("           SERVICIOS         \n");
        printf("-----------------------------\n");
        printf("  ID  | DESCRIPCION | PRECIO \n");
        printf("-----------------------------\n");
        for(int i=0; i<tamServ; i++)
        {
            printf("%-7d%-14s%-8.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }
        printf("\n");

        error=0;
    }
    return error;
}

int buscarServicio(eServicio servicios[], int tamServ, int id)
{
    int indiceId=-1;
    int i;

    if(servicios!=NULL && tamServ>0)
    {
        for(i=0; i<tamServ; i++)
        {
            if(servicios[i].id==id)
            {
                indiceId=i;
            }
        }
    }
    return indiceId;
}
