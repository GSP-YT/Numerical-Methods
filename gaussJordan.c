#include<stdio.h>
int main(){
    int i,j;
    // printf("Enter Number Of Equations : ");
    // scanf("%d", &i);
    i=3;
    j=i+1;
    // float e[i][j];
    // float e[3][4]={{9.0,5.0,3.0,4.0},{3.0,7.0,1.0,5.0},{3.0,0.0,5.0,8.0}};
    float e[3][4]={9, 1 ,2 ,3 ,4 , 5 , 6 , 7 , 8 , 9 , 10 , 11};
    // for(int n=0;n<i;n++){
    //     printf("Enter Equation %d : \n", n+1);
    //     for(int m=0;m<j;m++){
    //         printf("Enter Coefficient Of x%d : ", m+1);
    //         scanf("%f", &e[n][m]);
    //     }
    // }
    printf("Entered Equations : \n");
    for(int n=0;n<i;n++){
        for(int m=0;m<j;m++){
            printf("%f\t", e[n][m]);
        }
        printf("\n");
    }
    // Gauss-Jordan
    for(int n=0;n<i;n++){
        for(int m=n+1;m<i;m++){
            float fact = e[m][n]/e[n][n];
            printf("Factor - %f\n", fact);
            for(int l=0;l<j;l++){
                e[m][l]=e[m][l]- (fact * e[n][l]);
            }
        }
    }
    printf("Equations After Making Upper And Lower Triangular : \n");
    for(int n=0;n<i;n++){
        for(int m=0;m<j;m++){
            printf("%f\t", e[n][m]);
        }
        printf("\n");
    }
    //Making Diagonal
    for(int n=0;n<i;n++){
        float x=e[n][n];
        for(int m=0;m<j;m++){
            e[n][m] = e[n][m]/x;
        }
    }
    printf("Equations After Making Diagonally Identity\n");
    for(int n=0;n<i;n++){
        for(int m=0;m<j;m++){
            printf("%f\t", e[n][m]);
        }
        printf("\n");
    }
    return 0;
}