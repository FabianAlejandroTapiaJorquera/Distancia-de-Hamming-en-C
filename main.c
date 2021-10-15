// 1) Para dos palabras binarias de la misma longitud, la "distancia de Hamming" (propuesta por Richard Hamming) se define como la cantidad de bits distintos, en la misma posición, entre ambas palabras. Por ejemplo, la "distancia de Hamming" entre las palabras 111 y 010 es 2 ya que existen 2 bits distintos. Considerar typedef int palabra[64]; para implementar la función hamming(p, q, n) que calcule la "distancia de Hamming" entre las palabras p y q, ambas de n≤64 bits.

// 2) Con base en la definición typedef int binaria[100][100]; implementar la función veces(b, n, m) que retorne la cantidad de veces que aparece la secuencia 101 en todas y cada una de las m columnas de una matriz binaria b de n·m dígitos binarios (valores 0 o 1).

#include <stdlib.h>
#include <stdio.h>

typedef int palabra[64];
typedef int binaria[100][100];

int hamming(int*, int*, int);
int veces(binaria, int, int);

int main(){
    // 1)
    palabra p = {1,1,1,0,0,0,0,1};
    palabra q = {0,1,0,0,0,1,0,1};
    printf("La distancia de hamming es de %i\n", hamming(p, q, 8));

    // 2)
    binaria b = {
        {1,0,1}, 
        {0,1,1}, 
        {1,0,0}, 
        {0,1,0}, 
        {1,1,1}, 
        {0,1,0}
    };
    printf("\n\nMatriz\n\n");
    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++)
            printf("%i ",b[i][j]);
        printf("\n");
    }
    printf("\n\n");
    printf("Se detectaron %i secuencias de 101",veces(b, 6, 3));
    
    return 0;
}

// 1)
int hamming(int *p, int *q, int n){
    int contador = 0;
    for(int i=0; i<n; i++){
        if(p[i] != q[i]){
            contador++;
        }
    }
    return contador;
}

// 2)
int veces(binaria b, int n, int m){
    int contador = 0, i = 0;
    for(int j=0; j<m; j++){
        while(i+2 < n){
            if(b[i][j] == 1 && b[i+1][j] == 0 && b[i+2][j] == 1)
                contador++;
            printf("%i %i %i\n", b[i][j], b[i+1][j], b[i+2][j]);
            i++;
        }
        i=0;
        printf("\n");
    }
    return contador;
}


