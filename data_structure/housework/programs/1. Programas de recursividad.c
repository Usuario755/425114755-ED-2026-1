#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int facTail(int n, int a){
    
    
    if(n < 0){
        return 0;
    }
        
    else if (n == 0){
        return 1;
    }
        
    else if (n == 1){
        return a;
    }
        
    else {
        return facTail(n-1,n*a);
    }
        
}


int main (int argc, char *argv[]){
    
    char *num =argv[1];
    fprintf(stdout, "arg[1] = %s \n", argv[1]);
    
    for(int i=0;i<strlen(argv[1]);i++)
        fprintf(stdout,"num[%d]=%c \n", i, num[i]);
    
       int n = atoi(argv[1]); // convierte el primer argumento a entero
    int a = atoi(argv[2]); // convierte el segundo argumento a entero

    printf("Calculando facTail(%d, %d)...\n", n, a);
    
    printf("Resultado: %d\n", facTail(n, a));
    
    return 0;
}
