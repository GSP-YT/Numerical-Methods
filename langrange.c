#include<stdio.h>
int main(){
    int i=4;
    // printf("Enter Number Of Elements : ");
    // scanf("%d",&i);
    // float x[i],y[i],xn,p,fa;
    float x[4]={0,1,7,9},xn=8;
    float y[4]={18,42,57,90},l[i];;
    // printf("Enter X : \n");
    // for(int n=0;n<i;n++){
    //     scanf("%f",&x[n]);
    // }
    // printf("Enter Y : \n");
    // for(int n=0;n<1;n++){
    //     for(int m=0;m<i;m++){
    //         scanf("%f",&y[m][n]);
    //     }
    // }
    // printf("Enter X For You Want To find Y : ");
    // scanf("%f",&xn);
    //Calculating L
    for(int n=0;n<i;n++){
        l[n]=1;
        float nu=1,de=1;
        for(int m=0;m<i;m++){
            if(n==m){
                continue;
            }
            nu*=(xn-x[m]);
            de*=(x[n]-x[m]);
           
        }
        l[n]=nu/de; 
        printf("For l=%f  nu=%f de=%f\n",l[n],nu,de);
    }
    // Calculating Sum
    float sum;
    for(int n=0;n<i;n++){
        sum+=y[n]*l[n];
    }
    printf("For X=%f  Y=%f",xn,sum);
    return 0;
}