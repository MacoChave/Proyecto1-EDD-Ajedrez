#include <tgmath.h>

/*
 * METODOS PARA CASTEAR
 */
long convertir_cadena_a_entero(const char *cad)
{
    long num = 0;
    int tam  = strlen(cad);  /* Longitud de la cadena recibida */
    int digito;
    int i;

    for (i = tam ; i > 0; --i) {
        digito = (int) (cad[i - 1] - 48);
        num += digito * pow(10.0, tam - i);
    }

    return num;
}

char * convertir_entero_a_cadena(int num)
{
#define MAX_TAM 80

    char *cad;
    int digito;
    int i = 0;

    cad = (char*) malloc(MAX_TAM * sizeof(char));  /* No olvidar liberar la memoria asignada */
    memcpy(cad, "\0", MAX_TAM);  /* Bruto, pero efectivo :) */

    while (num >= 1) {
        digito = num % 10;

        if (i < MAX_TAM - 1) {
            cad[i] = (char) (digito + 48);
            num -= digito;
            num /= 10;
        }

        ++i;
    }

    /* Pero los dígitos de la cadena han quedado en orden inverso,  */
    /* así que los ordenamos correctamente */

    int  tam = strlen(cad);
    char temp;

    for (i = 0; i < tam / 2; ++i) {
        temp = cad[i];
        cad[i] = cad[tam - i - 1];
        cad[tam - i - 1] = temp;
    }

    return cad;
}
