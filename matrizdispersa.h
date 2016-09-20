#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

struct NodoColumna
{
    char* nombre; //IDENTIFICADOR PARA GRAFICAR
    int columna;
    struct NodoColumna* anterior;
    struct NodoColumna* siguiente;
    NodoColumna(int columna);
};

struct NodoFila
{
    char* nombre; //IDENTIFICADOR PARA GRAFICAR
    char* fila;
    struct NodoFila* arriba;
    struct NodoFila* abajo;
    NodoFila(char* fila);
};

struct NodoMatriz
{
    char* nombre; //IDENTIFICADOR PARA GRAFICAR
    int columna;
    char* fila;
    char* pieza;
    int nivel;
    char* color;
    struct NodoMatriz* izquierda;
    struct NodoMatriz* derecha;
    struct NodoMatriz* arriba;
    struct NodoMatriz* abajo;
    NodoMatriz(char* pieza, int columna, char* fila, int nivel, char* color);
};

struct Matriz{
    struct NodoColumna* listaColumna;
    struct NodoFila* listaFila;
    Matriz();
    void buscar(char* pieza, int columna, char* fila, int nivel, char* color);
    void insertar(char* pieza, int columna, char* fila, int nivel, char* color);
    void eliminar(char* pieza, int columna, char* fila, int nivel, char* color);
    void mover(char* pieza, int colOrg, char* filOrg, int nvlOrg, char* color, int colDest, char* filDest, int nvlDest);
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
void agregarNodoColumna(NodoMatriz** actual, NodoMatriz** nuevo);
void agregarNodoFila(NodoMatriz** actual, NodoMatriz** nuevo);

#endif // MATRIZDISPERSA_H
