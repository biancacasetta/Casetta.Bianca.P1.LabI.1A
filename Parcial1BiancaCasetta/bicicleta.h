#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

#include "tipo.h"
#include "color.h"

typedef struct{
    int id;
    char marca[21];
    int idTipo;
    int idColor;
    char material;
    int isEmpty;
}eBicicleta;

#endif // BICICLETA_H_INCLUDED

/** \brief Inicializa todos los campos isEmpty en 1 para que est�n disponibles para almacenar informaci�n en cada �ndice
 * \param bicicletas[] eBicicleta El array que se recorre para inicializarse como disponible
 * \param tamBici int El tama�o del array
 * \return int -1 si hubo error, 0 si no hubo error
 */
int inicializarBicicletas(eBicicleta bicicletas[], int tamBici);

/** \brief Busca el primer �ndice disponible en el array (isEmpty==1) para cargar los datos de una nueva estructura
 * \param bicicletas[] eBicicleta El array que se recorre para buscar el �ndice disponible
 * \param tamBici int El tama�o del array
 * \return int El n�mero del primer �ndice que se encuentra disponible para cargar una nueva estructura, -1 si no hay m�s lugar disponible
 */
int disponibilidadBicicletas(eBicicleta bicicletas[], int tamBici);

/** \brief Recorre un array para chequear si tiene �ndices ocupados y activa o desactiva una bandera que permite el ingreso a otras opciones (Modificar, Baja, Informar solo si hay Altas)
 * \param bicicletas[] eBicicleta Array a recorrer
 * \param tamBici int Tama�o del array
 * \param flag int* Puntero a entero de la bandera que debe activarse o desactivarse con 1 o 0 respectivamente
 * \return int -1 si hubo error, 0 si no hubo error
 */
int permitirIngreso(eBicicleta bicicletas[], int tamBici, int* flag);

/** \brief Ordena el array de estructuras por Tipo en primer lugar y Material en segundo lugar, si el Tipo es igual
 * \param bicicletas[] eBicicleta El array a ordenar
 * \param tamBici int El tama�o del array a ordenar
 * \param tipos[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tama�o del array de estructuras anidadas
 * \return int -1 si hubo error, 0 si no hubo error
 */
int ordenarBicicletasTipoMaterial(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo);

/** \brief Muestra los datos de una estructura individual
 * \param unaBicicleta eBicicleta La estructura espec�fica a mostrar
 * \param tipos[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tama�o del array de estructuras anidadas
 * \param colores[] eColor El array de estructuras anidadas
 * \param tamColor int El tama�o del array de estructuras anidadas
 * \return void No retorna ning�n valor
 */
void mostrarBicicleta(eBicicleta unaBicicleta, eTipo tipos[], int tamTipo, eColor colores[], int tamColor);

/** \brief Muestra una lista de los datos de m�ltiples estructuras
 * \param bicicletas[] eBicicleta El array de estructuras a mostrar
 * \param tamBici int El tama�o de del array a mostrar
 * \param tipos[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tama�o del array de estructuras anidadas
 * \param colores[] eColor El array de estructuras anidadas
 * \param tamColor int El tama�o del array de estructuras anidadas
 * \return int -1 si hubo error, 0 si no hubo error
 */
int mostrarBicicletas(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor);

/** \brief Recupera la descripci�n asociada al caracter ingresado por el usuario (C o A)
 * \param unaBicicleta eBicicleta La estructura donde se busca el caracter (C o A) y se recupera la descripci�n
 * \param descripcion[] char Cadena de caracteres donde se almacena la descripci�n que se busca
 * \return int -1 si hubo error, 0 si no hubo error.
 */
int cargarDescripcionMaterial(eBicicleta unaBicicleta, char descripcion[]);

/** \brief Da de alta una estructura en el primer �ndice disponible
 * \param bicicletas[] eBicicleta El array de estructuras donde se va a dar de alta la estructura
 * \param tamBici int El tama�o del array de estructuras
 * \param tipos[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tama�o del array de estructuras anidadas
 * \param colores[] eColor El array de estructuras anidadas
 * \param tamColor int El tama�o del array de estructuras anidadas
 * \param id int* Puntero a entero del ID a almacenar en el �ndice donde se da de alta la estructura
 * \return int -1 si hubo error, 0 si no hubo error
 */
int altaBicicleta(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, int* id);

/** \brief Recorre un array de estructuras para chequear que el ID ingresado por el usuario exista
 * \param bicicletas[] eBicicleta El array de estructuras a recorrer para validar que exista el ID
 * \param tamBici int El tama�o del array de estructuras
 * \param id int El ID ingresado por el usuario a comparar con los existentes
 * \return int El �ndice donde se encuentra el ID que coincide con el ingresado por el usuario, -1 si no existe
 */
int buscarBicicleta(eBicicleta bicicletas[], int tamBici, int id);

/** \brief Modifica un dato particular de la estructura en caso de que el usuario se haya equivocado al dar de alta
 * \param bicicletas[] eBicicleta El array de estructuras donde se realizar� la modificaci�n
 * \param tamBici int El tama�o del array de estructuras
 * \param tipos[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tama�o del array de estructuras anidadas
 * \param colores[] eColor El array de estructuras anidadas
 * \param tamColor int El tama�o del array de estructuras anidadas
 * \return int -1 si hubo error, 0 si no hubo error
 */
int modificarBicicleta(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor);

/** \brief Da de baja una estructura del ID que solicite el usuario
 * \param bicicletas[] eBicicleta El array de estructuras donde se encuentra el ID a dar de baja
 * \param tamBici int El tama�o del array de estructuras
 * \param tipos[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tama�o del array de estructuras anidadas
 * \param colores[] eColor El array de estructuras anidadas
 * \param tamColor int El tama�o del array de estructuras anidadas
 * \return int -1 si hubo error, 0 si no hubo error
 */
int bajaBicicleta(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor);

int mostrarBicicletasColores(eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamColor);
