#include <string.h>
#include <stdio.h>
#include <iostream>
#include <tgmath.h>

#include "matrizdispersa.h"

using namespace std;

int main()
{
    Matriz* matriz = new Matriz();
    matriz->insertar("peon", 5, "H", 2, "Negro");
    matriz->insertar("K", 4, "H", 1, "Negro");
    matriz->insertar("Q", 5, "H", 1, "Negro");
    matriz->insertar("A", 3, "H", 2, "Negro");
    matriz->insertar("T", 8, "H", 2, "Negro");

    /*
    int numero = 5;
    char* cadena = '4';

    cout << numero << " - " << cadena << endl;
    cout << (char*) (numero + 48) << endl;
    cout << (int) (cadena - 48) << endl;
    */

    /*
    int digito = 5;
    char* cadena = "4";

    cout << "DIGITO -> " << digito << endl;
    char* digitoACadena = convertir_entero_a_cadena(digito);
    cout << "CASTEADO -> " << digitoACadena << endl;

    cout << "CADENA -> " << cadena << endl;
    int cadenaADigito = convertir_cadena_a_entero(cadena);
    cout << "CASTEADO -> " << cadenaADigito << endl;

    char* concatenado = (char*)malloc(sizeof(char) * 80);
    strcpy(concatenado, cadena);
    strcat(concatenado, digitoACadena);
    cout << "CONCATENADO -> " << concatenado << endl;
    */
    return 0;
}
