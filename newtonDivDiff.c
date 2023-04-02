#include<stdio.h>
int main(){
    int i=4;
    // int i=5;
    // float x[5]={20,35,50,65,80},xn=24,fa;
    // float y[5][5]={{3},{11},{24},{50},{98}};
    printf("Enter Number Of Elements : ");
    scanf("%d",&i);
    float x[i],y[i][i],xn,fa;
    // float x[4]={0,6,20,45},xn=15,fa=1;
    // float y[4][4]={{30},{48},{88},{238}};
    for(int n=1;n<i;n++){
        for(int m=1;m<i-n;m++){
            y[m][n]=0;
        }
    }
    printf("Enter X : \n");
    for(int n=0;n<i;n++){
        scanf("%f",&x[n]);
    }
    printf("Enter Y : \n");
    for(int n=0;n<1;n++){
        for(int m=0;m<i;m++){
            scanf("%f",&y[m][n]);
        }
    }
    printf("Enter X For You Want To find Y : ");
    scanf("%f",&xn);
    //Calculating Table
    for(int n=1;n<i;n++){
        float z;
        for(int m=0;m<i-n;m++){
            z=x[m+n]-x[m];
            y[m][n]=(y[m+1][n-1]-y[m][n-1])/z;
        }
    }
    printf("X\t\tY\n");
    for(int n=0;n<i;n++){
        printf("%f\t",x[n]);
        for(int m=0;m<i-n;m++){
            printf("%f\t",y[n][m]);
        }
        printf("\n");
    }
    for(int m=0,n=0;m<i;m++){
        float mul=1;
        for(int z=0;z<m;z++){
            mul*=(xn-x[z]);
            // printf("mul=%f\n",mul);
        }
        fa+=(mul*y[n][m]);
        // printf("%f\t%f\t%f\n",(mul*y[n][m]),mul,y[n][m]);
    }
    printf("For X=%f  Y=%f",xn,fa);
    return 0;
}