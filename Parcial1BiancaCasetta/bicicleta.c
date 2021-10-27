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
                          "ID inválido. Ingrese el ID del tipo de bicicleta: ",
                          tipos[0].id,
                          tipos[tamTipo-1].id);

            mostrarColores(colores, tamColor);

            validarEntero(&auxBicicleta.idColor,
                          "Ingrese el ID del color de la bicicleta: ",
                          "ID inválido. Ingrese el ID del color de la bicicleta: ",
                          colores[0].id,
                          colores[tamColor-1].id);
            fflush(stdin);

            validarCaracter(&auxBicicleta.material,
                            "Ingrese el material (C=Carbono/A=Aluminio): ",
                            "Material inválido. Ingrese el material (C=Carbono/A=Aluminio): ",
                            'C', 'A');

            auxBicicleta.isEmpty=0;

            bicicletas[indiceDisponible]=auxBicicleta;

            system("cls");
            printf("Alta exitosa.\n");
            printf("Se ha dado de alta a la siguiente bicicleta: \n\n");

            printf(" ID |        MARCA        |   TIPO   |  COLOR  | MATERIAL \n");
            printf("----------------------------------------------------------\n");
            mostrarBicicleta(bicicletas[indiceDisponible], tipos, tamTipo, colores, tamColor);
            printf("\n");

            error=0;
        }
        else
        {
            printf("\nNo hay más lugar disponible para nuevas altas.\n\n");
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
                           "Respuesta inválida. Confirmar baja (S/N): ",
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
                                  "ID inválido. Ingrese el ID del tipo de bicicleta: ",
                                  tipos[0].id,
                                  tipos[tamTipo-1].id);
                    fflush(stdin);

                    bicicletas[indiceId].idTipo=auxBicicleta.idTipo;
                    break;
                case 'B':
                    validarCaracter(&auxBicicleta.material,
                                    "Ingrese el material (C=Carbono/A=Aluminio): ",
                                    "Material inválido. Ingrese el material (C=Carbono/A=Aluminio): ",
                                    'C', 'A');

                    bicicletas[indiceId].material=auxBicicleta.material;
                    break;
                case 'C':
                    printf("Modificación cancelada.\n\n");
                    break;
                default:
                    printf("Opción inválida. Ingrese una opción de la A a la C.\n");
                    break;
            }

            if(opcion=='A' || opcion=='B')
            {
                system("cls");
                printf("Modificación exitosa.\n");
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

int informarBicicletas(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    int error=-1;

    if(bicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipo>0 && colores!=NULL && tamColor>0)
    {
        system("cls");
        printf("                          INFORMES BICICLETAS                       \n");
        printf("--------------------------------------------------------------------\n");

        switch(subMenuInformesBicicletas())
        {
            case 'A':
                mostrarBicicletasColores(bicicletas, tamBici, tipos, tamTipo, colores, tamColor);
                break;
            case 'B':
                mostrarBicicletasTipos(bicicletas, tamBici, tipos, tamTipo, colores, tamColor);
                break;
            case 'C':
                mostrarMaterialMasElegido(bicicletas, tamBici, tipos, tamTipo, colores, tamColor);
                break;
            case 'D':
                mostrarBicicletasSeparadasTipo(bicicletas, tamBici, tipos, tamTipo, colores, tamColor);
                break;
            case 'E':
                contarBicicletasColorTipo(bicicletas, tamBici, tipos, tamTipo, colores, tamColor);
                break;
            case 'F':
                mostrarColorMasElegido(bicicletas, tamBici, tipos, tamTipo, colores, tamColor);
                break;
            default:
                printf("Opción inválida. Ingrese una opción de la A a la F.\n");
                fflush(stdin);
                break;
        }
        error=0;
    }
    return error;
}

int mostrarBicicletasColores(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    int error=-1;
    int idColor;
    int flag=0;
    char descColor[20];

    if(bicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipo>0 && colores!=NULL && tamColor>0)
    {
        system("cls");
        printf("                  BICICLETAS DE UN COLOR                  \n");
        printf("----------------------------------------------------------\n");

        mostrarColores(colores, tamColor);

        validarEntero(&idColor,
                      "Ingrese el ID del color de la bicicleta: ",
                      "ID inválido. Ingrese el ID del color de la bicicleta: ",
                      colores[0].id,
                      colores[tamColor-1].id);

        system("cls");
        printf("                  BICICLETAS DE UN COLOR                  \n");
        printf("----------------------------------------------------------\n");
        printf(" ID |        MARCA        |   TIPO   |  COLOR  | MATERIAL \n");
        printf("----------------------------------------------------------\n");

        for(int i=0; i<tamBici; i++)
        {
            if(!bicicletas[i].isEmpty && bicicletas[i].idColor==idColor)
            {
                mostrarBicicleta(bicicletas[i], tipos, tamTipo, colores, tamColor);
                flag=1;
            }
        }
        printf("\n");

        cargarDescripcionColor(colores, tamColor, idColor, descColor);

        if(!flag)
        {
            system("cls");
            printf("No hay bicicletas para mostrar de color %s.\n\n", descColor);
        }
        error=0;
    }

    return error;
}

int mostrarBicicletasTipos(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    int error=-1;
    int idTipo;
    int flag=0;
    char descTipo[20];

    if(bicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipo>0 && colores!=NULL && tamColor>0)
    {
        system("cls");
        printf("                   BICICLETAS DE UN TIPO                  \n");
        printf("----------------------------------------------------------\n");

        mostrarTipos(tipos, tamTipo);

        validarEntero(&idTipo,
                      "Ingrese el ID del tipo de la bicicleta: ",
                      "ID inválido. Ingrese el ID del tipo de la bicicleta: ",
                      tipos[0].id,
                      tipos[tamTipo-1].id);

        system("cls");
        printf("                   BICICLETAS DE UN TIPO                  \n");
        printf("----------------------------------------------------------\n");
        printf(" ID |        MARCA        |   TIPO   |  COLOR  | MATERIAL \n");
        printf("----------------------------------------------------------\n");

        for(int i=0; i<tamBici; i++)
        {
            if(!bicicletas[i].isEmpty && bicicletas[i].idTipo==idTipo)
            {
                mostrarBicicleta(bicicletas[i], tipos, tamTipo, colores, tamColor);
                flag=1;
            }
        }
        printf("\n");

        cargarDescripcionTipo(tipos, tamTipo, idTipo, descTipo);

        if(!flag)
        {
            system("cls");
            printf("No hay bicicletas para mostrar de tipo %s.\n\n", descTipo);
        }
        error=0;
    }

    return error;
}

int mostrarMaterialMasElegido(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    int error=-1;
    int cantCarbono=0;
    int cantAluminio=0;
    int cantMaxMaterial=0;
    int bicicletasPorMaterial[2];
    char descMaterial[20];

    if(bicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipo>0 && colores!=NULL && tamColor>0)
    {
        system("cls");
        printf("                    MATERIAL MAS ELEGIDO                  \n");
        printf("----------------------------------------------------------\n\n");

        for(int i=0; i<tamBici; i++)
        {
            if(!bicicletas[i].isEmpty && bicicletas[i].material=='C')
            {
                cantCarbono++;
            }
            else if(!bicicletas[i].isEmpty && bicicletas[i].material=='A')
            {
                cantAluminio++;
            }
            bicicletasPorMaterial[0]=cantCarbono;
            bicicletasPorMaterial[1]=cantAluminio;
        }

        for(int i=0; i<2; i++)
        {
            if(!i || cantMaxMaterial<bicicletasPorMaterial[i])
            {
                cantMaxMaterial=bicicletasPorMaterial[i];
            }
        }

        system("cls");

        for(int i=0; i<2; i++)
        {
            if(!i)
            {
                strcpy(descMaterial, "Carbono");
            }
            else
            {
                strcpy(descMaterial, "Aluminio");
            }

            if(bicicletasPorMaterial[i]==cantMaxMaterial)
            {
                printf("El material más elegido de bicicleta es %s con %d bicicleta(s).\n", descMaterial, cantMaxMaterial);
            }
        }

        printf("\n");

        error=0;
    }
    return error;
}

int mostrarBicicletasSeparadasTipo(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    int error=-1;
    char descTipo[20];
    int flag=0;

    if(bicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipo>0 && colores!=NULL && tamColor>0)
    {
        system("cls");
        printf("                    BICICLETAS POR TIPO                   \n");
        printf("----------------------------------------------------------\n\n");

        for(int i=0; i<tamTipo; i++)
        {
            flag=0;
            cargarDescripcionTipo(tipos, tamTipo, tipos[i].id, descTipo);
            printf("Tipo: %s\n\n",descTipo);

            printf(" ID |        MARCA        |   TIPO   |  COLOR  | MATERIAL \n");
            printf("----------------------------------------------------------\n");

            for(int j=0; j<tamBici; j++)
            {
                if(!bicicletas[j].isEmpty && bicicletas[j].idTipo==tipos[i].id)
                {
                    mostrarBicicleta(bicicletas[j], tipos, tamTipo, colores, tamColor);
                    flag=1;
                }
            }
            printf("\n");

            if(!flag)
            {
                printf("No hay bicicletas para mostrar de tipo %s.\n\n", descTipo);
            }
        }
        error=0;
    }
    return error;
}

int contarBicicletasColorTipo(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    int error=-1;
    int idColor;
    int idTipo;
    int cantBicicletas=0;
    char descColor[20];
    char descTipo[20];

    if(bicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipo>0 && colores!=NULL && tamColor>0)
    {
        system("cls");
        printf("               BICICLETAS DE UN COLOR Y TIPO              \n");
        printf("----------------------------------------------------------\n");

        mostrarColores(colores, tamColor);

        validarEntero(&idColor,
                      "Ingrese el ID del color de la bicicleta: ",
                      "ID inválido. Ingrese el ID del color de la bicicleta: ",
                      colores[0].id,
                      colores[tamColor-1].id);

        mostrarTipos(tipos, tamTipo);

        validarEntero(&idTipo,
                      "Ingrese el ID del tipo de la bicicleta: ",
                      "ID inválido. Ingrese el ID del tipo de la bicicleta: ",
                      tipos[0].id,
                      tipos[tamTipo-1].id);

        system("cls");
        printf("               BICICLETAS DE UN COLOR Y TIPO              \n");
        printf("----------------------------------------------------------\n");
        printf(" ID |        MARCA        |   TIPO   |  COLOR  | MATERIAL \n");
        printf("----------------------------------------------------------\n");

        for(int i=0; i<tamBici; i++)
        {
            if(!bicicletas[i].isEmpty && bicicletas[i].idColor==idColor && bicicletas[i].idTipo==idTipo)
            {
                mostrarBicicleta(bicicletas[i], tipos, tamTipo, colores, tamColor);
                cantBicicletas++;
            }
        }

        cargarDescripcionColor(colores, tamColor, idColor, descColor);
        cargarDescripcionTipo(tipos, tamTipo, idTipo, descTipo);

        if(!cantBicicletas)
        {
            system("cls");
            printf("No hay ninguna bicicleta de color %s y tipo %s.\n\n", descColor, descTipo);
        }
        else
        {
            printf("\nHay %d bicicleta(s) de color %s y tipo %s.\n\n", cantBicicletas, descColor, descTipo);
        }

        error=0;
    }
    return error;
}

int mostrarColorMasElegido(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    int error=-1;
    int bicicletasPorColor[tamColor];
    int cantidadMaxColor=0;

    if(bicicletas!=NULL && tamBici>0 && tipos!=NULL && tamTipo>0 && colores!=NULL && tamColor>0)
    {
        system("cls");
        printf("                     COLOR MAS ELEGIDO                    \n");
        printf("----------------------------------------------------------\n");

        for(int i=0; i<tamColor; i++)
        {
            for(int j=0; j<tamBici; j++)
            {
                if(!bicicletas[j].isEmpty && bicicletas[j].idColor==colores[i].id)
                {
                    cantidadMaxColor++;
                }
            }
            bicicletasPorColor[i]=cantidadMaxColor;

            cantidadMaxColor=0;
        }

        for(int i=0; i<tamColor; i++)
        {
            if(!i || cantidadMaxColor<bicicletasPorColor[i])
            {
                cantidadMaxColor=bicicletasPorColor[i];
            }
        }

        system("cls");

        for(int i=0; i<tamColor; i++)
        {
            if(bicicletasPorColor[i]==cantidadMaxColor)
            {
                printf("El color más elegido de bicicleta es %s con %d bicicleta(s).\n", colores[i].nombreColor, cantidadMaxColor);
            }
        }
        printf("\n");

        error=0;
    }
    return error;
}
