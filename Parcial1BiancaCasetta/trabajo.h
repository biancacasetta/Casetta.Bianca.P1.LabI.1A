#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "fecha.h"
#include "bicicleta.h"
#include "servicio.h"
#include "color.h"

typedef struct{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

/** \brief Inicializa todos los campos isEmpty en 1 para que est�n disponibles para almacenar informaci�n en cada �ndice
 * \param trabajos[] eTrabajo El array que se recorre para inicializarse como disponible
 * \param tamTrab int El tama�o del array
 * \return int -1 si hubo error, 0 si no hubo error
 */
int inicializarTrabajos(eTrabajo trabajos[], int tamTrab);

/** \brief Busca el primer �ndice disponible en el array (isEmpty==1) para cargar los datos de una nueva estructura
 * \param trabajos[] eTrabajo El array que se recorre para buscar el �ndice disponible
 * \param tamTrab int El tama�o del array
 * \return int El n�mero del primer �ndice que se encuentra disponible para cargar una nueva estructura, -1 si no hay m�s lugar disponible
 */
int disponibilidadTrabajos(eTrabajo trabajos[], int tamTrab);

/** \brief Muestra los datos de una estructura individual
 * \param unTrabajo eTrabajo La estructura espec�fica a mostrar
 * \param bicicletas[] eBicicletas El array de estructuras anidadas
 * \param tamBici int El tama�o del array de estructuras anidadas
 * \param tipos[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tama�o del array de estructuras anidadas
 * \param colores[] eColor El array de estructuras anidadas
 * \param tamColor int El tama�o del array de estructuras anidadas
 * \param servicios[] eColor El array de estructuras anidadas
 * \param tamServ int El tama�o del array de estructuras anidadas
 * \return void No retorna ning�n valor
 */
void mostrarTrabajo(eTrabajo unTrabajo, eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, eServicio servicios[], int tamServ);

/** \brief Muestra una lista de los datos de m�ltiples estructuras
 * \param trabajos[] eTrabajo El array de estructuras a mostrar
 * \param tamTrab int El tama�o del array a mostrar
 * \param bicicletas[] eBicicletas El array de estructuras anidadas
 * \param tamBici int El tama�o del array de estructuras anidadas
 * \param tipos[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tama�o del array de estructuras anidadas
 * \param colores[] eColor El array de estructuras anidadas
 * \param tamColor int El tama�o del array de estructuras anidadas
 * \param servicios[] eColor El array de estructuras anidadas
 * \param tamServ int El tama�o del array de estructuras anidadas
 * \return int -1 si hubo error, 0 si no hubo error
 */
int mostrarTrabajos(eTrabajo trabajos[], int tamTrab, eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, eServicio servicios[], int tamServ);

/** \brief Da de alta una estructura en el primer �ndice disponible
 * \param trabajos[] eTrabajo El array de estructuras a mostrar
 * \param tamTrab int El tama�o del array a mostrar
 * \param bicicletas[] eBicicletas El array de estructuras anidadas
 * \param tamBici int El tama�o del array de estructuras anidadas
 * \param tipos[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tama�o del array de estructuras anidadas
 * \param colores[] eColor El array de estructuras anidadas
 * \param tamColor int El tama�o del array de estructuras anidadas
 * \param servicios[] eColor El array de estructuras anidadas
 * \param tamServ int El tama�o del array de estructuras anidadas
 * \param id int* Puntero a entero del ID a almacenar en el �ndice donde se da de alta la estructura
 * \return int -1 si hubo error, 0 si no hubo error
 */
int altaTrabajo(eTrabajo trabajos[], int tamTrab, eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, eServicio servicios[], int tamServ, int* id);

#endif // TRABAJO_H_INCLUDED
