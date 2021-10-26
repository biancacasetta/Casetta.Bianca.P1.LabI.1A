#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "fecha.h"

int validarFecha(eFecha* fecha)
{
    int error=1;

    printf("Ingrese la fecha (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);

    while(error==1)
    {
        if(fecha->anio>=1900 && fecha->anio<=2021)
        {
            if(fecha->mes>=1 && fecha->mes<=12)
            {
                switch(fecha->mes)
                {
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        if(fecha->dia<1 || fecha->dia>31)
                        {
                            printf("Día inválido para el mes %02d (1-31). Ingrese la fecha (DD/MM/AAAA): ", fecha->mes);
                            scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
                        }
                        else
                        {
                            error=0;
                        }
                        break;
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        if(fecha->dia<1 || fecha->dia>30)
                        {
                            printf("Día inválido para el mes %02d (1-30). Ingrese la fecha (DD/MM/AAAA): ", fecha->mes);
                            scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
                        }
                        else
                        {
                            error=0;
                        }
                        break;
                    case 2:
                        if(fecha->anio%4==0 || (fecha->anio%100!=0 && fecha->anio%400==0))
                        {
                            if(fecha->dia<1 || fecha->dia>29)
                            {
                                printf("Día inválido para el mes %02d (1-29). Ingrese la fecha (DD/MM/AAAA): ", fecha->mes);
                                scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
                            }
                            else
                            {
                                error=0;
                            }
                        }
                        else
                        {
                            if(fecha->dia<1 || fecha->dia>28)
                            {
                                printf("Día inválido para el mes %02d (1-28). Ingrese la fecha (DD/MM/AAAA): ", fecha->mes);
                                scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
                            }
                            else
                            {
                                error=0;
                            }
                        }
                        break;
                }
            }
            else
            {
                printf("Mes inválido (1-12). Ingrese la fecha (DD/MM/AAAA): ");
                scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
            }
        }
        else
        {
            printf("Año inválido (1900-2021). Ingrese la fecha (DD/MM/AAAA): ");
            scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
        }
    }

    return error;
}
