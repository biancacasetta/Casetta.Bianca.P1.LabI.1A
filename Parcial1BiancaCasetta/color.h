#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id;
    char nombreColor[21];
}eColor;

#endif // COLOR_H_INCLUDED

/** \brief Busca la coincidencia de un ID ingresado por el usuario y un ID existente y recupera la descripci�n asociada a ese ID
 * \param colores[] eColor El array donde se busca el ID y se recupera la descripci�n
 * \param tamColor int El tama�o del array que se recorre
 * \param idColor int El ID ingresado por el usuario a comparar
 * \param nombreColor[] char Cadena de caracteres donde se almacena la descripci�n que se busca
 * \return int -1 si hubo error, 0 si no hubo error.
 */
int cargarDescripcionColor(eColor colores[], int tamColor, int idColor, char nombreColor[]);

/** \brief Muestra un listado de colores
 * \param colores[] eColor El array a mostrar
 * \param tamColor int El tama�o del array que se muestra
 * \return int -1 si hubo error, 0 si no hubo error.
 */
int mostrarColores(eColor colores[], int tamColor);
