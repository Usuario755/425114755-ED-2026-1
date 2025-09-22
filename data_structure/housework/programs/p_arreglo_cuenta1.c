// p_arreglo_cuenta.c
#include <stdio.h>

int main() {
    int pares[10];
    int i;

   
    for (i = 0; i < 10; i++) {
        pares[i] = (i + 1) * 2;
    }

    printf("Arreglo original:\n");
    for (i = 0; i < 10; i++) {
        printf("Indice %d | Valor %d\n", i, pares[i]);
    }

    
    long long numero = 425114755;

  
    int ultimo_digito = numero % 10;

    
    if (ultimo_digito >= 0 && ultimo_digito < 10) {
        pares[ultimo_digito] = -1;
    }


    printf("\nArreglo modificado:\n");
    for (i = 0; i < 10; i++) {
        printf("Indice %d | Valor %d\n", i, pares[i]);
    }

    return 0;
}
