#include<stdio.h>
int main(){
    int i,j,a,d;
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
    float x[i],y[i];
    for(int m=0;m<i;m++){
        x[m]=0;
        y[m]=0;
    }
    printf("X1\t\tX2\t\tX3\n");
    for(int q=0;q<10;q++){
        for(int n=0;n<i;n++){
            int m=0;
            for(m=0;m<j-1;m++){
                if(n==m){
                    a=e[n][m];
                    continue;
                }
                x[n]+=e[n][m]*y[m];
            }
            x[n]=e[n][m]-x[n];
            x[n]=x[n]/a;
            printf("%f\t", x[n]);
        }
        printf("\n");
        if(x[i-1]==y[i-1]){
            break;
        }
        for(int m=0;m<i;m++){
            y[m]=x[m];
            x[m]=0;
        }
    }
    return 0;
}