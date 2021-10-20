#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"
#include "input.h"
#include "bicicleta.h"
#include "servicio.h"
#include "fecha.h"

int inicializarTrabajos(eTrabajo trabajos[], int tamTrab)
{
    int error=-1;

    if(trabajos!=NULL && tamTrab>0)
    {
        for(int i=0;i<tamTrab;i++)
        {
            trabajos[i].isEmpty=1;
        }
        error=0;
    }
    return error;
}

int disponibilidadTrabajos(eTrabajo trabajos[], int tamTrab)
{
    int indiceDisponible=-1;

    if(trabajos!=NULL && tamTrab>0)
    {
        for(int i=0; i<tamTrab; i++)
        {
            if(trabajos[i].isEmpty)
            {
                indiceDisponible=i;
                break;
            }
        }
    }
    return indiceDisponible;
}

void mostrarTrabajo(eTrabajo unTrabajo, eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, eServicio servicios[], int tamServ)
{
    char descTipo[20];
    char descColor[20];
    char descMaterial[20];
    char descServicio[20];
    int indiceBicicleta;
    int indiceServicio;

    if(bicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipo>0 && colores!=NULL && tamColor>0 && servicios!=NULL && tamServ>0)
    {
        indiceBicicleta=buscarBicicleta(bicicletas, tamBici, unTrabajo.idBicicleta);
        indiceServicio=buscarServicio(servicios, tamServ, unTrabajo.idServicio);

        cargarDescripcionTipo(tipos, tamTipo, bicicletas[indiceBicicleta].idTipo, descTipo);
        cargarDescripcionColor(colores, tamColor, bicicletas[indiceBicicleta].idColor, descColor);
        cargarDescripcionServicio(servicios, tamServ, unTrabajo.idServicio, descServicio);
        cargarDescripcionMaterial(bicicletas[indiceBicicleta], descMaterial);


        printf("%-5d%-5d%-22s%-11s%-10s%-11s%-14s%-9.2f%02d/%02d/%d\n",
                unTrabajo.id,
                bicicletas[indiceBicicleta].id,
                bicicletas[indiceBicicleta].marca,
                descTipo,
                descColor,
                descMaterial,
                descServicio,
                servicios[indiceServicio].precio,
                unTrabajo.fecha.dia,
                unTrabajo.fecha.mes,
                unTrabajo.fecha.anio);
    }
}

int mostrarTrabajos(eTrabajo trabajos[], int tamTrab, eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, eServicio servicios[], int tamServ)
{
    int error=-1;
    int i;
    int flag=0;

    if(bicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipo>0 && colores!=NULL && tamColor>0)
    {
        printf(" ID |                       BICICLETA                          |       SERVICIO       |   FECHA   \n");
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("    | ID |        MARCA        |   TIPO   |  COLOR  | MATERIAL | DESCRIPCION | PRECIO |           \n");
        printf("--------------------------------------------------------------------------------------------------\n");


        ordenarBicicletasTipoMaterial(bicicletas, tamBici, tipos, tamTipo);

        for(i=0; i<tamTrab; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                mostrarTrabajo(trabajos[i], bicicletas, tamBici, tipos, tamTipo, colores, tamColor, servicios, tamServ);
                flag=1;
            }
        }

        printf("\n");

        if(!flag)
        {
            printf("No hay trabajos para mostrar.\n\n");
        }
        error=0;
    }

    return error;
}

int altaTrabajo(eTrabajo trabajos[], int tamTrab, eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, eServicio servicios[], int tamServ, int* id)
{
    int error=-1;
    int indiceDisponible;
    eTrabajo auxTrabajo;

    if(trabajos!=NULL && tamTrab>0 && bicicletas!=NULL && tamBici>0 && servicios!=NULL && tamServ>0 && id!=NULL)
    {
        indiceDisponible=disponibilidadTrabajos(trabajos, tamTrab);

        if(indiceDisponible>=0)
        {
            auxTrabajo.id=*id;

            system("cls");
            printf("                          ALTA DE TRABAJO                          \n");
            printf("-------------------------------------------------------------------\n");

            mostrarBicicletas(bicicletas, tamBici, tipos, tamTipo, colores, tamColor);
            printf("Ingrese el ID de la bicicleta para el trabajo: ");
            scanf("%d", &auxTrabajo.idBicicleta);
            fflush(stdin);

            while(validarIdBicicleta(bicicletas, tamBici, auxTrabajo.idBicicleta)==-1)
            {
                mostrarBicicletas(bicicletas, tamBici, tipos, tamTipo, colores, tamColor);
                printf("ID inv�lido. Ingrese el ID de la bicicleta para el trabajo: ");
                scanf("%d", &auxTrabajo.idBicicleta);
                fflush(stdin);
            }

            mostrarServicios(servicios, tamServ);
            validarEntero(&auxTrabajo.idServicio,
                          "Ingrese el ID del servicio: ",
                          "ID inv�lido. Ingrese el ID del servicio: ",
                          servicios[0].id,
                          servicios[tamServ-1].id);
            fflush(stdin);

            validarFecha(&auxTrabajo.fecha);

            auxTrabajo.isEmpty=0;

            trabajos[indiceDisponible]=auxTrabajo;

            system("cls");
            printf("Alta exitosa.\n");
            printf("Se ha dado de alta al siguiente trabajo: \n\n");

            printf(" ID |                       BICICLETA                          |       SERVICIO       |   FECHA   \n");
            printf("--------------------------------------------------------------------------------------------------\n");
            printf("    | ID |        MARCA        |   TIPO   |  COLOR  | MATERIAL | DESCRIPCION | PRECIO |           \n");
            printf("--------------------------------------------------------------------------------------------------\n");
            mostrarTrabajo(trabajos[indiceDisponible], bicicletas, tamBici, tipos, tamTipo, colores, tamColor, servicios, tamServ);
            printf("\n");

            error=0;
        }
        else
        {
            printf("\nNo hay m�s lugar disponible para nuevas altas.\n\n");
        }
    }

    return error;
}
