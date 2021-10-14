// Para dos palabras binarias de la misma longitud, la "distancia de Hamming" (propuesta por Richard Hamming) se define como la cantidad de bits distintos, en la misma posición, entre ambas palabras. Por ejemplo, la "distancia de Hamming" entre las palabras 111 y 010 es 2 ya que existen 2 bits distintos. Considerar typedef int palabra[64]; para implementar la función hamming(p, q, n) que calcule la "distancia de Hamming" entre las palabras p y q, ambas de n≤64 bits.

#include <stdlib.h>
#include <stdio.h>

typedef int palabra[64];

int hamming(int*, int*, int);

int main(){
    palabra p = {1,1,1,0,0,0,0,1};
    palabra q = {0,1,0,0,0,1,0,1};
    printf("La distancia de hamming es de %i", hamming(p, q, 8));
    return 0;
}

int hamming(int *p, int *q, int n){
    int contador = 0;
    for(int i=0; i<n; i++){
        if(p[i] != q[i]){
            contador++;
        }
    }
    return contador;
}

