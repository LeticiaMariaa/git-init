/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//NUMERO MENOR PARA MAIOR
#include <stdio.h> 
int main () {
   int i, k, troca, A[10] = {5,2,3,1,4,6,9,8,0,7};
   for(k=0; k<9; k++){
   for(i=0; i < 9 - k; i++){
       if(A[i+1]<A[i]){
        troca = A[i];
        A[i] = A[i+1];
        A[i+1] = troca;
       }
     }
   }
   printf("Numero menor para maior:\n");
   for(i=0; i < 10; i++){
   printf("%d", A[i]);
   }
   for(k=0; k<9; k++){
   for(i=0; i < 9 - k; i++){
       if(A[i+1]>A[i]){
        troca = A[i];
        A[i] = A[i+1];
        A[i+1] = troca;
       }
     }
   }
   printf("\nNumero maior para menor:\n");
   for(i=0; i < 10; i++){
   printf("%d", A[i]);
   }
    return 0;
}

/*#include <stdio.h> 
int main () {
   int i, k, troca, A[10] = {5,2,3,1,4,6,9,8,0,7};
   for(k=0; k<9; k++){
   for(i=0; i < 9 - k; i++){
       if(A[i+1]>A[i]){
        troca = A[i];
        A[i] = A[i+1];
        A[i+1] = troca;
       }
     }
   }
   printf("Numero maior para menor");
   for(i=0; i < 10; i++){
   printf("%d", A[i]);
   }
    return 0;
}
*/
