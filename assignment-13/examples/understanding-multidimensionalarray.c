#include <stdio.h>

int main()
{

    //4 "matrizes" com 3 elementos cada,ai fica tipo uma tabela de x e y. sendo i = 0 e j = 0 ---> 1
    int arr[4][3] = { {1,2,3},{4,5,6},{7,8,9,},{10,11,12} };
    int *pontarr;
    int i = 0;
    int j = i;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("arr[i=%d][j=%d] = %d",i,j, arr[i][j]);
            printf("\t");
        }
        printf("\n");
    }

    printf("=================================================================================================================================\n");


    //Memória
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("&arr[i=%d][j=%d] = %X", i, j, &arr[i][j]);
            printf("\t");
        }
        printf("\n");
    }

    printf("=================================================================================================================================\n");


    //Todos os valores!
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%x -- %d -- %d -- %d", arr[i] , i , j, *(arr[i] +j));
            printf("\t");
        }
        printf("\n");
    }

    printf("=================================================================================================================================\n");

    pontarr = &arr[0][0];
    
    //Com Ponteiro!
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d", *(( &(pontarr)[i * 4] )  + j)  );  //parenteses dessa forma sao lidos de dentro para fora
            printf("\t");
        }
        printf("\n");
    }
}