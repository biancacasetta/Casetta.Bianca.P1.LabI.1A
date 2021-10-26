#ifndef HARDCODE_H_INCLUDED
#define HARDCODE_H_INCLUDED
#endif // HARDCODE_H_INCLUDED

#include "bicicleta.h"


/** \brief Carga previa de datos para facilitar el testeo del programa
 * \param bicicletas[] eBicicleta Array a recorrer para ir cargando datos
 * \param tamBici int El tamaño del array a recorrer
 * \param cantidad int Cantidad de items que se desea incluir en el hardcodeo
 * \param id int* Puntero a entero
 * \return int contador -1 si hubo error
 */
int hardcodearBicicletas(eBicicleta bicicletas[], int tamBici, int cantidad, int* id);

int hardcodearTrabajos(eTrabajo trabajos[], int tamTrab, int cantidad, int* id);
