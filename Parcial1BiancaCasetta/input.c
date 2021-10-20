#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "bicicleta.h"

char menu()
{
    char opcion;

    printf("          SISTEMA DE BICICLETERIA       \n");
    printf("----------------------------------------\n");
    printf("            MENU DE OPCIONES            \n");
    printf("----------------------------------------\n");
    printf("A. ALTA BICICLETA\n");
    printf("B. MODIFICAR BICICLETA\n");
    printf("C. BAJA BICICLETA\n");
    printf("D. LISTAR BICICLETAS\n");
    printf("E. LISTAR TIPOS\n");
    printf("F. LISTAR COLORES\n");
    printf("G. LISTAR SERVICIOS\n");
    printf("H. ALTA TRABAJO\n");
    printf("I. LISTAR TRABAJOS\n");
    printf("J. SALIR\n\n");
    printf("Ingrese una opción: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion=toupper(opcion);

    return opcion;
}

char subMenuModificar()
{
    char opcion;

    printf("\nA. TIPO\n");
    printf("B. MATERIAL\n");
    printf("C. CANCELAR\n\n");
    printf("Seleccione el dato que desea modificar: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion=toupper(opcion);
    printf("\n");

    return opcion;
}

int soloLetras(char cadena[])
{
    int error=0;
    int i=0;

    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(!isalpha(cadena[i]) && cadena[i]!=' ')
            {
                error=-1;

                while(error<0)
                {
                    printf("Solo puede ingresar letras. Inténtelo de nuevo (hasta 20 caracteres): ");
                    gets(cadena);
                    error=0;
                    i=0;
                }
            }
            i++;
        }
    }
    return error;
}

int inicialMayuscula(char cadena[])
{
    int error=-1;
    int i=0;

    strlwr(cadena);
    cadena[0]=toupper(cadena[0]);

    while(cadena[i]!='\0')
    {
        if(cadena[i]==' ')
        {
            cadena[i+1]=toupper(cadena[i+1]);
            error=0;
        }
        i++;
    }
    return error;
}

int validarCadena(char cadena[], char mensaje[], char mensajeError[], int min, int max)
{
    int error=-1;
	char aux[100];

	if(cadena!=NULL && mensaje!=NULL && mensajeError!=NULL && min>0 && max>min)
	{
		printf("%s", mensaje);
		fflush(stdin);
		gets(aux);
		soloLetras(aux);

		while(strlen(aux)<min|| strlen(aux)>max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			gets(aux);
			soloLetras(aux);
		}
		inicialMayuscula(aux);

		strcpy(cadena, aux);
		error=0;
	}

	return error;
}

int validarCaracter(char* caracter, char mensaje[], char mensajeError[], char caracterValido1, char caracterValido2)
{
    int error=-1;
    char caracterIngresado;

	if(caracter!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &caracterIngresado);
		caracterIngresado=toupper(caracterIngresado);

		while(caracterIngresado!=caracterValido1 && caracterIngresado!=caracterValido2)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%c", &caracterIngresado);
			caracterIngresado=toupper(caracterIngresado);
		}

        *caracter=caracterIngresado;
		error=0;
	}

	return error;
}

int validarFlotante(float* numero, char mensaje[], char mensajeError[], float min, float max)
{
    int error=-1;
    float numeroIngresado;

	if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL && min<max)
	{
		printf("%s", mensaje);
		scanf("%f", &numeroIngresado);

		while(numeroIngresado<min || numeroIngresado>max)
		{
			printf("%s", mensajeError);
			scanf("%f", &numeroIngresado);
		}

        *numero=numeroIngresado;
		error=0;
	}

	return error;
}

int validarEntero(int* numero, char mensaje[], char mensajeError[], int min, int max)
{
    int error=-1;
    int numeroIngresado;

	if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL && min<max)
	{
		printf("%s", mensaje);
		scanf("%d", &numeroIngresado);

		while(numeroIngresado<min || numeroIngresado>max)
		{
			printf("%s", mensajeError);
			scanf("%d", &numeroIngresado);
		}

        *numero=numeroIngresado;
		error=0;
	}

	return error;
}

int validarIdBicicleta(eBicicleta bicicletas[], int tamBici, int idBicicleta)
{
    int error=-1;;

    if(bicicletas!=NULL && tamBici>0)
    {
        for(int i=0; i<tamBici; i++)
        {
            if(bicicletas[i].id==idBicicleta)
            {
                error=0;
            }
        }
    }
    return error;
}
