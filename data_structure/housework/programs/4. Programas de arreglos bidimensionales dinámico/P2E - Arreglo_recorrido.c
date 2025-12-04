
#include <stdio.h>
#define m 4
#define n 4

//Recorrido por fila comenzando desde la casilla 00, siguiento 01, 02, 03 ... luego 10, 11... hasta 
//nm.
void recorrido1(int matriz[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j =0; j <m; j++) {
            printf("matriz[%d][%d] = %d\n", j, i, matriz[j][i]);
        }
    }
}

//Recorrido por iumnas comenzando desde nm, n−1m, n−2m, hasta 0m, para continuar con nm−1, n−1m−1, 
//n−2m... 0m−1.. el proceso deberá continuar hasta llegar a la casilla 00
void recorrido2(int matriz[n][m]) {
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            printf("matriz[%d][%d] = %d\n", j, i, matriz[j][i]);
        }
    }
}

//Realice el recorrido en diagonal desde la casilla 00, 11, 22, 33, siempre que 
//n=m, considere el caso donde n≠m, n<m o >m

void recorrido3(int matriz[n][m] ) {
    int limite = (n < m) ? n : m;

    for (int i = 0; i < limite; i++) {
        printf("matriz[%d][%d] = %d\n", i, i, matriz[i][i]);
    }
}

int main() {
    int op;
    int matriz[n][m] = {
        {1, 2, 3, 25},
        {4, 5, 6, 34},
        {7, 8, 9, 23},
        {10, 11, 12, 13}
        
    };
    do{
        printf("\nSelecciones una opcion");
        printf("\n Recorrido 1 \n Recorrido 2 \n Recorrido 3 ");
        printf("\nSeleccion:");
        scanf("%d",&op);
        switch(op){
            case 1:
                recorrido1(matriz);
                break;
            case 2:
                recorrido2(matriz);
                break;
            case 3:
                recorrido3(matriz);
                break;
            default:
                printf("\nOpcion invalida");
        }    
    }while(op !=4);
    
    
    
    return 0;
}
