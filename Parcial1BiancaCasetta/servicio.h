#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[26];
    float precio;
}eServicio;

/** \brief Busca la coincidencia de un ID ingresado por el usuario y un ID existente y recupera la descripción asociada a ese ID
 * \param servicios[] eServicio El array donde se busca el ID y se recupera la descripción
 * \param tamServ int El tamaño del array que se recorre
 * \param idServicio int El ID ingresado por el usuario a comparar
 * \param descripcion[] char Cadena de caracteres donde se almacena la descripción que se busca
 * \return int -1 si hubo error, 0 si no hubo error.
 */
int cargarDescripcionServicio(eServicio servicios[], int tamServ, int idServicio, char descripcion[]);

/** \brief Muestra un listado de servicios
 * \param servicios[] eServicio El array a mostrar
 * \param tamServ int El tamaño del array que se muestra
 * \return int -1 si hubo error, 0 si no hubo error.
 */
int mostrarServicios(eServicio servicios[], int tamServ);

/** \brief Recorre un array de estructuras para chequear que el ID ingresado por el usuario exista
 * \param servicios[] eServicio El array de estructuras a recorrer para validar que exista el ID
 * \param tamServ int El tamaño del array de estructuras
 * \param id int El ID ingresado por el usuario a comparar con los existentes
 * \return int El índice donde se encuentra el ID que coincide con el ingresado por el usuario, -1 si no existe
 */
int buscarServicio(eServicio servicios[], int tamServ, int id);

#endif // SERVICIO_H_INCLUDED
