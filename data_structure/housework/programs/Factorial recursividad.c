//Es funcional?
//recursiva
#include <stdio.h>

facTail(n, a){
    a--;
    
    if(n < 0){
        return 0;
    }
        
    else if (n = 0){
        return 1;
    }
        
    else if (n = 1){
        return a;
    }
        
    else {
        return facTail(n-1,n*a);
    }
        
}
    

    

int main(){
    int n=1, a;
    //printf("Enter an number: ");
    //scanf("%d", &a);
    //printf("Enter another number: ");
    //scanf("%d", &a);
    printf("%d",facTail(n,a));
    return 1;
}
