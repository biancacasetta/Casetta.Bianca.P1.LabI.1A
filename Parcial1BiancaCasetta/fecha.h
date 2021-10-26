#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

/** \brief Valida una fecha ingresada en formato (DD/MM/AAAA) de forma que el usuario no pueda ingresar fechas inexistentes (ej 30 de febrero / 29 de febrero en un año que no es bisiesto)
 * \param fecha eFecha* La fecha a validar
 * \return int 1 si hubo error, 0 si no hubo error
 */
int validarFecha(eFecha* fecha);

#endif // FECHA_H_INCLUDED
