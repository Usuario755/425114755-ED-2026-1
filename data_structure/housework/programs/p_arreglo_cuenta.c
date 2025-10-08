//Realice un programa en C que genere una lista de los primeros 
//10 números pares, deberá imprimirlos en orden inverso.

// p_arreglo_cuenta.c
#include <stdio.h>

int main() {
    int pares[10];
    int i;


    for (i = 0; i < 10; i++) {
        pares[i] = (i + 1) * 2;
    }


    printf("Los primeros 10 números pares en orden inverso son:\n");
    for (i = 9; i >= 0; i--) {
        printf("%d ", pares[i]);
    }

    printf("\n");
    return 0;
}

