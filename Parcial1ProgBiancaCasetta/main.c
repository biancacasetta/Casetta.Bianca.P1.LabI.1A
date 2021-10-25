#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_NBK 5
#define ASC 1
#define DESC 0
 /*
1. Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto
y devuelva el valor del producto con un descuento del 5%. Realizar la llamada desde el main.
2. Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer parámetro
y un carácter como segundo y devuelva la cantidad de veces que ese carácter aparece en la cadena
3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array de dicha estructura por marca.
Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main.
*/

typedef struct{
    int id;
    char procesador[10];
    char marca[20];
    float precio;
}Notebook;

float aplicarDescuento(float precio);
int contarCaracteres(char palabra[], char caracter);
int ordenarNotebooksMarcaPrecio(Notebook notebooks[], int tamNotebooks, int criterio);

int main()
{
    float precioACalcular=2850.00;
    float precioDescuento;
    char palabra[20]="Bianca Casetta";
    char caracter='a';
    int cantidadLetra;
    Notebook notebooks[TAM_NBK]={{1000,"i5","Intel",5000.00},
                                 {1001,"i9","Intel", 9450.00},
                                 {1002,"i7","Intel",7720.00},
                                 {1003,"Ryzen 3","AMD",6500.00},
                                 {1004,"Ryzen 7","AMD",9800.00}};

    precioDescuento=aplicarDescuento(precioACalcular);
    printf("El precio de %.2f con 5%% de descuento es %.2f.\n\n", precioACalcular, precioDescuento);

    cantidadLetra=contarCaracteres(palabra, caracter);
    printf("El caracter %c aparece %d veces en la palabra %s.\n", caracter, cantidadLetra, palabra);

    ordenarNotebooksMarcaPrecio(notebooks, TAM_NBK, ASC);
    return 0;
}

//Funcion 1
float aplicarDescuento(float precio)
{
    float precioDescuento;

    precioDescuento=precio*0.95;

    return precioDescuento;
}

//Funcion 2
int contarCaracteres(char palabra[], char caracter)
{
    int contador=0;

    if(palabra!=NULL)
    {
        for(int i=0; i<strlen(palabra); i++)
        {
            if(palabra[i]==caracter)
            {
                contador++;
            }
        }
    }
    return contador;
}

//Funcion 3
int ordenarNotebooksMarcaPrecio(Notebook notebooks[], int tamNotebooks, int criterio)
{
    int error=-1;
    Notebook auxNotebook;

    if(notebooks!=NULL && tamNotebooks>0 && criterio<=1 && criterio>=0)
    {
        if(criterio)
        {
            for(int i=0; i<tamNotebooks-1; i++)
            {
                for(int j=i+1; j<tamNotebooks; j++)
                {
                    if(strcmp(notebooks[i].marca, notebooks[j].marca)>0 || (!strcmp(notebooks[i].marca, notebooks[j].marca) && notebooks[i].precio>notebooks[j].precio))
                    {
                        auxNotebook=notebooks[i];
                        notebooks[i]=notebooks[j];
                        notebooks[j]=auxNotebook;
                    }
                }
            }
        }
        else if(!criterio)
        {
            for(int i=0; i<tamNotebooks-1; i++)
            {
                for(int j=i+1; j<tamNotebooks; j++)
                {
                    if(strcmp(notebooks[i].marca, notebooks[j].marca)<0 || (!strcmp(notebooks[i].marca, notebooks[j].marca) && notebooks[i].precio<notebooks[j].precio))
                    {
                        auxNotebook=notebooks[i];
                        notebooks[i]=notebooks[j];
                        notebooks[j]=auxNotebook;
                    }
                }
            }
        }

        printf("\n   NOTEBOOKS POR MARCA Y PRECIO   \n");
        printf("----------------------------------\n");
        printf(" ID | PROCESADOR | MARCA | PRECIO \n");
        printf("----------------------------------\n");

        for(int i=0; i<tamNotebooks; i++)
        {
            printf("%-5d%-13s%-8s%-8.2f\n",
                   notebooks[i].id,
                   notebooks[i].procesador,
                   notebooks[i].marca,
                   notebooks[i].precio);
        }
        error=0;
    }
    return error;
}
