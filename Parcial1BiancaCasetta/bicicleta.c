#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"

int inicializarBicicletas(eBicicleta bicicletas[], int tamBici)
{
    int error=-1;

    if(bicicletas!=NULL && tamBici>0)
    {
        for(int i=0;i<tamBici;i++)
        {
            bicicletas[i].isEmpty=1;
        }
        error=0;
    }
    return error;
}

int disponibilidadBicicletas(eBicicleta bicicletas[], int tamBici)
{
    int indiceDisponible=-1;

    if(bicicletas!=NULL && tamBici>0)
    {
        for(int i=0; i<tamBici; i++)
        {
            if(bicicletas[i].isEmpty)
            {
                indiceDisponible=i;
                break;
            }
        }
    }
    return indiceDisponible;
}

int permitirIngreso(eBicicleta bicicletas[], int tamBici, int* flag)
{
    int error=-1;

    for(int i=0; i<tamBici; i++)
    {
        if(bicicletas[i].isEmpty)
        {
            *flag=0;
        }
        else
        {
            *flag=1;
            break;
        }
    }
    return error;
}

int ordenarBicicletasTipoMaterial(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo)
{
    int error=-1;
    eBicicleta auxBicicleta;
    char descTipo1[9];
    char descTipo2[9];

    if(bicicletas!=NULL && tamBici> 0)
    {
        for(int i=0; i<tamBici-1; i++)
        {
            for(int j=i+1; j<tamBici; j++)
            {
                cargarDescripcionTipo(tipos, tamTipo, bicicletas[i].idTipo, descTipo1);
                cargarDescripcionTipo(tipos, tamTipo, bicicletas[j].idTipo, descTipo2);

                if(strcmp(descTipo1, descTipo2)>0 || (strcmp(descTipo1, descTipo2)==0 && bicicletas[i].material>bicicletas[j].material))
                {
                    auxBicicleta=bicicletas[i];
                    bicicletas[i]=bicicletas[j];
                    bicicletas[j]=auxBicicleta;
                }
            }
        }
        error=0;
    }
    return error;
}

void mostrarBicicleta(eBicicleta unaBicicleta, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    char descTipo[20];
    char descColor[20];
    char descMaterial[20];

    if(tipos!=NULL && tamTipo>0 && colores!=NULL && tamColor>0)
    {

        cargarDescripcionTipo(tipos, tamTipo, unaBicicleta.idTipo, descTipo);
        cargarDescripcionColor(colores, tamColor, unaBicicleta.idColor, descColor);
        cargarDescripcionMaterial(unaBicicleta, descMaterial);

        printf("%-5d%-22s%-11s%-10s%-10s\n",
                unaBicicleta.id,
                unaBicicleta.marca,
                descTipo,
                descColor,
                descMaterial);
    }
}

int mostrarBicicletas(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    int error=-1;
    int i;
    int flag=0;

    if(bicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipo>0 && colores!=NULL && tamColor>0)
    {
        printf(" ID |        MARCA        |   TIPO   |  COLOR  | MATERIAL \n");
        printf("----------------------------------------------------------\n");

        ordenarBicicletasTipoMaterial(bicicletas, tamBici, tipos, tamTipo);

        for(i=0; i<tamBici; i++)
        {
            if(!bicicletas[i].isEmpty)
            {
                mostrarBicicleta(bicicletas[i], tipos, tamTipo, colores, tamColor);
                flag=1;
            }
        }

        printf("\n");

        if(!flag)
        {
            printf("No hay bicicletas para mostrar.\n\n");
        }
        error=0;
    }

    return error;
}

int cargarDescripcionMaterial(eBicicleta unaBicicleta, char descripcion[])
{
    int error=-1;

    if(descripcion!=NULL)
    {
        if(unaBicicleta.material=='C')
        {
            strcpy(descripcion, "Carbono");
            error=0;
        }
        else if(unaBicicleta.material=='A')
        {
            strcpy(descripcion, "Aluminio");
            error=0;
        }
    }
    return error;
}

int altaBicicleta(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, int* id)
{
    int error=-1;
    int indiceDisponible;
    eBicicleta auxBicicleta;

    if(bicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipo>0 && colores!=NULL && tamColor>0 && id!=NULL)
    {
        indiceDisponible=disponibilidadBicicletas(bicicletas, tamBici);

        if(indiceDisponible>=0)
        {
            auxBicicleta.id=*id;

            system("cls");
            printf("                         ALTA DE BICICLETA                         \n");
            printf("-------------------------------------------------------------------\n\n");

            validarCadena(auxBicicleta.marca,
                          "Ingrese la marca de la bicicleta (1 a 20 caracteres): ",
                          "Marca demasiado larga. Ingrese la marca de la bicicleta (1 a 20 caracteres): ",
                          1,
                          20);

            mostrarTipos(tipos, tamTipo);

            validarEntero(&auxBicicleta.idTipo,
                          "Ingrese el ID del tipo de bicicleta: ",
                          "ID inv�lido. Ingrese el ID del tipo de bicicleta: ",
                          tipos[0].id,
                          tipos[tamTipo-1].id);

            mostrarColores(colores, tamColor);

            validarEntero(&auxBicicleta.idColor,
                          "Ingrese el ID del color de la bicicleta: ",
                          "ID inv�lido. Ingrese el ID del color de la bicicleta: ",
                          colores[0].id,
                          colores[tamColor-1].id);
            fflush(stdin);

            validarCaracter(&auxBicicleta.material,
                            "Ingrese el material (C=Carbono/A=Aluminio): ",
                            "Material inv�lido. Ingrese el material (C=Carbono/A=Aluminio): ",
                            'C', 'A');

            auxBicicleta.isEmpty=0;

            bicicletas[indiceDisponible]=auxBicicleta;

            system("cls");
            printf("\nAlta exitosa.\n");
            printf("Se ha dado de alta a la siguiente bicicleta: \n\n");

            printf(" ID |        MARCA        |   TIPO   |  COLOR  | MATERIAL \n");
            printf("----------------------------------------------------------\n");
            mostrarBicicleta(bicicletas[indiceDisponible], tipos, tamTipo, colores, tamColor);
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

int buscarBicicleta(eBicicleta bicicletas[], int tamBici, int id)
{
    int indiceId=-1;
    int i;

    if(bicicletas!=NULL && tamBici>0)
    {
        for(i=0; i<tamBici; i++)
        {
            if(!bicicletas[i].isEmpty && bicicletas[i].id==id)
            {
                indiceId=i;
            }
        }
    }
    return indiceId;
}

int bajaBicicleta(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    int error=-1;
    int indiceId;
    int idIngresado;
    char confirmacion;

    if(bicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipo>0 && colores!=NULL && tamColor>0)
    {
        system("cls");
        printf("                          BAJA DE BICICLETA                       \n");
        printf("------------------------------------------------------------------\n");
        mostrarBicicletas(bicicletas, tamBici, tipos, tamTipo, colores, tamColor);
        printf("\nIngrese el ID de la bicicleta a dar de baja: ");
        scanf("%d", &idIngresado);
        fflush(stdin);
        printf("\n");

        indiceId=buscarBicicleta(bicicletas, tamBici, idIngresado);

        if(indiceId>=0)
        {
            printf(" ID |        MARCA        |   TIPO   |  COLOR  | MATERIAL \n");
            printf("----------------------------------------------------------\n");
            mostrarBicicleta(bicicletas[indiceId], tipos, tamTipo, colores, tamColor);

            validarCaracter(&confirmacion,
                           "\nConfirmar baja (S/N): ",
                           "Respuesta inv�lida. Confirmar baja (S/N): ",
                           'S',
                           'N');

            if(confirmacion=='S')
            {
                bicicletas[indiceId].isEmpty=1;
                error=0;

                system("cls");
                printf("Baja exitosa.\n");
                printf("Se ha dado de baja a la siguiente bicicleta: \n\n");
                printf(" ID |        MARCA        |   TIPO   |  COLOR  | MATERIAL \n");
                printf("----------------------------------------------------------\n");
                mostrarBicicleta(bicicletas[indiceId], tipos, tamTipo, colores, tamColor);
                printf("\n");
            }
        }
        else
        {
            printf("No existe el ID ingresado.\n\n");
        }
    }
    return error;
}

int modificarBicicleta(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    int error=-1;
    int indiceId;
    int idIngresado;
    eBicicleta auxBicicleta;
    char opcion;

    if(bicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipo>0 && colores!=NULL && tamColor>0)
    {
        system("cls");
        printf("                          MODIFICAR BICICLETA                       \n");
        printf("--------------------------------------------------------------------\n");
        mostrarBicicletas(bicicletas, tamBici, tipos, tamTipo, colores, tamColor);
        printf("\nIngrese el ID de la bicicleta a modificar: ");
        scanf("%d", &idIngresado);
        fflush(stdin);
        printf("\n");

        indiceId=buscarBicicleta(bicicletas, tamBici, idIngresado);

        if(indiceId>=0)
        {
            system("cls");
            printf(" ID |        MARCA        |   TIPO   |  COLOR  | MATERIAL \n");
            printf("----------------------------------------------------------\n");
            mostrarBicicleta(bicicletas[indiceId], tipos, tamTipo, colores, tamColor);

            opcion=subMenuModificar();

            switch(opcion)
            {
                case 'A':
                    mostrarTipos(tipos, tamTipo);

                    validarEntero(&auxBicicleta.idTipo,
                                  "Ingrese el ID del tipo de bicicleta: ",
                                  "ID inv�lido. Ingrese el ID del tipo de bicicleta: ",
                                  tipos[0].id,
                                  tipos[tamBici-1].id);
                    fflush(stdin);

                    bicicletas[indiceId].idTipo=auxBicicleta.idTipo;
                    break;
                case 'B':
                    validarCaracter(&auxBicicleta.material,
                                    "Ingrese el material (C=Carbono/A=Aluminio): ",
                                    "Material inv�lido. Ingrese el material (C=Carbono/A=Aluminio): ",
                                    'C', 'A');

                    bicicletas[indiceId].material=auxBicicleta.material;
                    break;
                case 'C':
                    printf("\n");
                    break;
                default:
                    printf("Opci�n inv�lida. Ingrese una opci�n de la A a la C.\n");
                    break;
            }

            if(opcion=='A' || opcion=='B')
            {
                system("cls");
                printf("Modificaci�n exitosa.\n");
                printf("Se ha modificado a la siguiente bicicleta: \n\n");
                printf(" ID |        MARCA        |   TIPO   |  COLOR  | MATERIAL \n");
                printf("----------------------------------------------------------\n");
                mostrarBicicleta(bicicletas[indiceId], tipos, tamTipo, colores, tamColor);
                printf("\n");
            }

            error=0;
        }
        else
        {
            printf("No existe el ID ingresado.\n\n");
        }
    }
    return error;
}
