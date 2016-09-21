#include <stdio.h>
#include <string.h>

#include "castear.cpp"
#include "matrizdispersa.h"

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
    if ((*actual) == NULL || strcmp((*actual)->fila, f) > 0)
    {
        //LISTA FILA VACIA O INSERCION POR DELANTE
        NodoFila* nuevo = new NodoFila(f);
        if ((*actual) != NULL)
        {
            //INSERSION POR DELANTE
            nuevo->abajo = (*actual);
            if ((*actual)->arriba != NULL)
            {
                (*actual)->arriba->abajo = nuevo;
                nuevo->arriba = (*actual)->arriba;
            }
            (*actual)->arriba = nuevo;
        }
        (*actual) = nuevo;

        return &nuevo;
    } else
    {
        //LISTA FILA CON AL MENOS UN ELEMENTO
        if ((*actual)->abajo != NULL && strcmp((*actual)->fila, f) < 0)
        {
            //SE PUEDE AVANZAR EN LA LISTA
            return agregar(&((*actual)->abajo), f);
        } else if (strcmp((*actual)->fila, f) == 0)
        {
            //NODO FILA YA SE ENCUENTRA
            return actual;
        } else
        {
            NodoFila* nuevo = new NodoFila(f);
            if ((*actual)->abajo != NULL);
            {
                //APUNTAR EL SIGUIENTE DE NODO FILA ACTUAL A NODO FILA NUEVO
                nuevo->abajo = (*actual)->abajo;
                (*actual)->arriba = nuevo;
            }
            (*actual)->abajo = nuevo;
            nuevo->arriba = (*actual);

            return &nuevo;
        }
    }
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
    NodoFila** filaTemp = NULL;

    columnaTemp = agregar(&(this->listaColumna), columna);
    filaTemp = agregar(&(this->listaFila), fila);
}
