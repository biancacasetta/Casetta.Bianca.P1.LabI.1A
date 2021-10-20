#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[21];
}eTipo;

/** \brief Busca la coincidencia de un ID ingresado por el usuario y un ID existente y recupera la descripción asociada a ese ID
 * \param tipos[] eTipo El array donde se busca el ID y se recupera la descripción
 * \param tamTipo int El tamaño del array que se recorre
 * \param idTipo int El ID ingresado por el usuario a comparar
 * \param descripcion[] char Cadena de caracteres donde se almacena la descripción que se busca
 * \return int -1 si hubo error, 0 si no hubo error.
 */
int cargarDescripcionTipo(eTipo tipos[], int tamTipo, int idTipo, char descripcion[]);

/** \brief Muestra un listado de tipos
 * \param tipos[] eTipo El array a mostrar
 * \param tamTipo int El tamaño del array que se muestra
 * \return int -1 si hubo error, 0 si no hubo error.
 */
int mostrarTipos(eTipo tipos[], int tamTipo);

#endif // TIPO_H_INCLUDED
