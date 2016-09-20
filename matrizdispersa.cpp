#include <stdio.h>
#include <string.h>
#include <tgmath.h>

#include "matrizdispersa.h"

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


/*
 * NODO COLUMNA
 */
NodoColumna::NodoColumna(int columna)
{
    this->columna = columna;
    this->anterior = NULL;
    this->siguiente = NULL;

    char* nombre = "NODO";
    char* c = convertir_entero_a_cadena(columna);
    char* id = (char*)malloc(sizeof(char) * 80);
    strcpy(id, nombre);
    strcat(id, c);
    this->nombre = id;
}

/*
 * NODO FILA
 */
NodoFila::NodoFila(char *fila)
{
    this->fila = fila;
    this->abajo = NULL;
    this->arriba = NULL;

    char* nombre = "NODO";
    char* id = (char*)malloc(sizeof(char) * 80);
    strcpy(id, nombre);
    strcat(id, fila);
    this->nombre = id;
}

/*
 * NODO MATRIZ
 */
NodoMatriz::NodoMatriz(char *pieza, int columna, char *fila, int nivel, char* color)
{
    this->pieza = pieza;
    this->columna = columna;
    this->fila = fila;
    this->nivel = nivel;
    this->color = color;
    this->abajo = NULL;
    this->arriba = NULL;
    this->izquierda = NULL;
    this->derecha = NULL;

    char* nombre = "NODO";
    char* n = convertir_entero_a_cadena(nivel);
    char* c = convertir_entero_a_cadena(columna);
    char* id = (char*)malloc(sizeof(char) * 80);
    strcpy(id, nombre);
    strcat(id, c);
    strcat(id, fila);
    strcat(id, n);
    this->nombre = id;
}

/*
 * Matriz
 */
Matriz::Matriz()
{
    this->listaColumna = NULL;
    this->listaFila = NULL;
}

/*
 * METODOS PARA LISTA COLUMNA
 */
NodoColumna** agregar(NodoColumna **actual, int c)
{
    if ((*actual) == NULL || (*actual)->columna > c)
    {
        //COLUMNA ES VACIA O INSERCION DELANTE
        NodoColumna* nuevo = new NodoColumna(c);
        if ((*actual) != NULL)
        {
            //INSERCION POR DELANTE
            nuevo->siguiente = (*actual);
            if ((*actual)->anterior != NULL)
            {
                (*actual)->anterior->siguiente = nuevo;
                nuevo->anterior = (*actual)->anterior;
            }
            (*actual)->anterior = nuevo;
        }
        (*actual) = nuevo;

        return &nuevo;
    } else
    {
        //COLUMNA CON AL MENOS UN ELEMENTO
        if ((*actual)->siguiente != NULL && (*actual)->columna < c)
        {
            //AVANZAR A SIGUIENTE NODO COLUMNA
            return agregar(&((*actual)->siguiente), c);
        } else if ((*actual)->columna == c)
        {
            return actual;
        } else
        {
            NodoColumna* nuevo = new NodoColumna(c);
            if ((*actual)->siguiente != NULL)
            {
                //ENLAZAR ACTUAL CON ACTUAL.SIGUIENTE
                nuevo->siguiente = (*actual)->siguiente;
                (*actual)->anterior = nuevo;
            }
            (*actual)->siguiente = nuevo;
            nuevo->anterior = (*actual);

            return &nuevo;
        }
    }
}


/*
 * METODOS PARA LISTA FILA
 */
NodoFila** agregar(NodoFila** actual, char* f)
{

}

/*
 * METODOS PARA LISTA NODO MATRIZ
 */
void agregarNodoColumna(NodoMatriz **actual, NodoMatriz **nuevo)
{

}

void agregarNodoFila(NodoMatriz **actual, NodoMatriz **nuevo)
{

}

/*
 * METODOS PARA MATRIZ
 */
void Matriz::insertar(char *pieza, int columna, char *fila, int nivel, char* color)
{
    NodoColumna** columnaTemp = NULL;
    //NodoFila** filaTemp = NULL;

    columnaTemp = agregar(&(this->listaColumna), columna);
    //filaTemp = agregar(&(this->listaFila), fila);
}
