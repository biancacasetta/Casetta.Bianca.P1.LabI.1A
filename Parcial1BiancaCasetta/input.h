#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#endif // INPUT_H_INCLUDED

#include "bicicleta.h"

/** \brief Muestra un menú inicial de opciones para seleccionar
 * \return char La opción seleccionada por el usuario, para luego usar de criterio en un switch
 */
char menu();

/** \brief Muestra un submenú cuando se selecciona la opción Modificar con las opciones de datos que se pueden cambiar
 * \return char La opción seleccionada por el usuario, para luego usar de criterio en un switch
 */
char subMenuModificar();

/** \brief Muestra un submenú cuando se selecciona la opción Informes de Bicicletas con las opciones de informes que se pueden mostrar
 * \return char La opción seleccionada por el usuario, para luego usar de criterio en un switch
 */
char subMenuInformesBicicletas();

/** \brief Muestra un submenú cuando se selecciona la opción Informes de Trabajos con las opciones de informes que se pueden mostrar
 * \return char La opción seleccionada por el usuario, para luego usar de criterio en un switch
 */
char subMenuInformesTrabajos();

/** \brief Valida que la cadena de caracteres ingresada contenga letras únicamente, sin permitir números ni símbolos
 * \param cadena[] char La cadena de caracteres a validar
 * \return int 1 si hubo error, 0 si no hubo error
 */
int soloLetras(char cadena[]);

/** \brief Formatea una cadena de caracteres de manera que la(s) inicial(es) sea(n) mayúscula y el resto, minúsculas
 * \param cadena[] char La cadena de caracteres a formatear
 * \return 1 si hubo error, 0 si no hubo error
 */
int inicialMayuscula(char cadena[]);

/** \brief Valida que una cadena de caracteres no supere la cantidad máxima de caracteres permitidos, ni que no ingrese nada
 * \param cadena[] char La cadena de caracteres a validar
 * \param mensaje[] char El mensaje a mostrar como prompt para que el usuario ingrese la cadena de caracteres
 * \param mensajeError[] char El mensaje de error en caso de que la cadena supere el límite de caracteres o no ingrese nada
 * \param min int El mínimo de caracteres a ingresar (al menos 1)
 * \param max int El máximo de caracteres a ingresar (según corresponda)
 * \return 1 si hubo error, 0 si no hubo error
 */
int validarCadena(char cadena[], char mensaje[], char mensajeError[], int min, int max);

/** \brief Valida que un caracter esté dentro de las opciones válidas (generalmente usado para prompts de SI o NO O S/N)
 * \param caracter char* Puntero a caracter del caracter ingresado por el usuario
 * \param mensaje[] char El mensaje a mostrar como prompt para que el usuario ingrese el caracter
 * \param mensajeError[] char El mensaje de error en caso de que el caracter no sea ninguno de los válidos
 * \param caracterValido1 char Una de las opciones válidas de caracter ingresado
 * \param caracterValido2 char Otra de las opciones válidas de caracter ingresado
 * \return 1 si hubo error, 0 si no hubo error
 */
int validarCaracter(char* caracter, char mensaje[], char mensajeError[], char caracterValido1, char caracterValido2);

/** \brief Valida que un número flotante esté dentro de un rango específico y que no se ingresen letras o símbolos antes del flotante
 * \param numero float* Puntero a flotante del número flotante ingresado por el usuario
 * \param mensaje[] char El mensaje a mostrar como prompt para que el usuario ingrese el número flotante
 * \param mensajeError[] char El mensaje de error en caso de que el número flotante se encuentre fuera del rango válido
 * \param min float El mínimo número flotante válido
 * \param max float El máximo número flotante válido
 * \return 1 si hubo error, 0 si no hubo error
 */
int validarFlotante(float* numero, char mensaje[], char mensajeError[], float min, float max);

/** \brief Valida que un número entero esté dentro de un rango específico y que no se ingresen letras o símbolos antes del entero
 * \param numero int* Puntero a entero del número entero ingresado por el usuario
 * \param mensaje[] char El mensaje a mostrar como prompt para que el usuario ingrese el número entero
 * \param mensajeError[] char El mensaje de error en caso de que el número entero se encuentre fuera del rango válido
 * \param min float El mínimo número entero válido
 * \param max float El máximo número entero válido
 * \return 1 si hubo error, 0 si no hubo error
 */
int validarEntero(int* numero, char mensaje[], char mensajeError[], int min, int max);
