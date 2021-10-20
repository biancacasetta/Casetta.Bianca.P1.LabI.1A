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
#include "hardcode.h"

#define TAMBICI 20
#define TAMTRAB 20
#define TAMTIPO 4
#define TAMCOLOR 5
#define TAMSERV 4

int main()
{
    char seguir='s';
    char salir;
    int nextIdBicicleta=1;
    int nextIdTrabajo=1;
    int opcionA=0;
    int opcionH=0;
    eBicicleta bicicletas[TAMBICI];
    eTrabajo trabajos[TAMTRAB];

    eTipo tipos[TAMTIPO]={{1000, "Rutera"},{1001,"Carrera"},{1002,"Mountain"},{1003,"BMX"}};
    eColor colores[TAMCOLOR]={{5000,"Gris"},{5001,"Blanco"},{5002,"Azul"},{5003,"Negro"},{5004,"Rojo"}};
    eServicio servicios[TAMSERV]={{20000,"Limpieza",300.00},{20001,"Parche",400.00},{20002,"Centrado",500.00},{20003,"Cadena",450.00}};

    inicializarBicicletas(bicicletas, TAMBICI);
    inicializarTrabajos(trabajos, TAMTRAB);

    //hardcodearBicicletas(bicicletas, TAMBICI, 10, &nextIdBicicleta);
    //opcionA=1;

    do
    {
        system("cls");

        switch(menu())
        {
            case 'A':
                altaBicicleta(bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR, &nextIdBicicleta);
                nextIdBicicleta++;
                opcionA=1;
                break;
            case 'B':
                if(opcionA)
                {
                    modificarBicicleta(bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR);
                }
                else
                {
                    printf("\nNo hay ninguna bicicleta dada de alta para modificar.\n\n");
                }
                break;
            case 'C':
                if(opcionA)
                {
                    bajaBicicleta(bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR);
                }
                else
                {
                    printf("\nNo hay ninguna bicicleta dada de alta para dar de baja.\n\n");
                }
                permitirIngreso(bicicletas, TAMBICI, &opcionA);
                break;
            case 'D':
                if(opcionA)
                {
                    system("cls");
                    mostrarBicicletas(bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR);
                }
                else
                {
                    printf("\nNo hay ninguna bicicleta dada de alta para listar.\n\n");
                }
                break;
            case 'E':
                system("cls");
                mostrarTipos(tipos, TAMTIPO);
                break;
            case 'F':
                system("cls");
                mostrarColores(colores, TAMCOLOR);
                break;
            case 'G':
                system("cls");
                mostrarServicios(servicios, TAMSERV);
                break;
            case 'H':
                if(opcionA)
                {
                    altaTrabajo(trabajos, TAMTRAB, bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR, servicios, TAMSERV, &nextIdTrabajo);
                }
                else
                {
                    printf("\nNo hay ninguna bicicleta dada de alta para dar de alta un trabajo.\n\n");
                }
                nextIdTrabajo++;
                opcionH=1;
                break;
            case 'I':
                if(opcionH)
                {
                    mostrarTrabajos(trabajos, TAMTRAB, bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR, servicios, TAMSERV);
                }
                else
                {
                    printf("No hay ning�n trabajo dado de alta para listar.\n");
                }
                break;
            case 'J':
                validarCaracter(&salir, "\nConfirmar salida (S/N): ", "Opci�n inv�lida. Confirmar salida (S/N): ", 'S', 'N');

                if(salir=='S')
                {
                    seguir='n';
                }
                break;
            default:
                printf("Opci�n inv�lida. Ingrese una opci�n de la A a la J.\n");
                fflush(stdin);
                break;
        }
        system("pause");
    }while(seguir=='s');

    return 0;
}
