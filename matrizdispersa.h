#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

struct NodoColumna
{
    char* id; //IDENTIFICADOR PARA GRAFICAR
    int columna;
    struct NodoColumna* anterior;
    struct NodoColumna* siguiente;
    NodoColumna(int columna);
};

struct NodoFila
{
    char* id; //IDENTIFICADOR PARA GRAFICAR
    char* fila;
    struct NodoFila* arriba;
    struct NodoFila* abajo;
    NodoFila(char* fila);
};

struct NodoMatriz
{
    char* id; //IDENTIFICADOR PARA GRAFICAR
    char* pieza;
    int nivel;
    struct NodoMatriz* izquierda;
    struct NodoMatriz* derecha;
    struct NodoMatriz* arriba;
    struct NodoMatriz* abajo;
    NodoMatriz(char* pieza, int nivel);
};

struct Matriz{
    struct NodoColumna* listaColumna;
    struct NodoFila* listaFila;
    Matriz();
    bool buscar(char* pieza, int columna, char* fila, int nivel);
    bool agregar(char* pieza, int columna, char* fila, int nivel);
    bool eliminar(char* pieza, int columna, char* fila, int nivel);
    bool mover(char* pieza, int colOrg, char* filOrg, int nvlOrg, int colDest, char* filDest, int nvlDest);
    void linealizarFila();
    void linealizarColumna();
};

typedef struct NodoColumna NodoColumna;
typedef struct NodoFila NodoFila;
typedef struct NodoMatriz NodoMatriz;
typedef struct Matriz Matriz;

/*
 * METODOS PARA LISTA COLUMNA
 */
NodoColumna** agregar(NodoColumna** actual, int c);
void mostrar(NodoColumna* actual);

/*
 * METODOS PARA LISTA FILA
 */
NodoFila** agregar(NodoFila** actual, char* f);
void mostrar(NodoFila* actual);

/*
 * METODOS PARA LISTA NODO MATRIZ
 */
bool agregarNodoColumna(NodoMatriz** actual, NodoMatriz** nuevo);
bool agregarNodoFila(NodoMatriz** actual, NodoMatriz** nuevo);

#endif // MATRIZDISPERSA_H
