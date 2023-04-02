#include<stdio.h>
float fact(float p){
    float f;
    if(p==0){
        return 1;
    }
    f=p*fact(p-1);
    return f;
}
int main(){
    int i=5;
    printf("Enter Number Of Elements : ");
    scanf("%d",&i);
    float x[i],y[i][i],xn,p,fa;
    // float x[5]={0,10,20,30,40},xn=35,p,fa;
    // float y[5][5]={{7},{18},{32},{51},{87}};
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
        for(int m=0;m<i-n;m++){
            y[m][n]=y[m+1][n-1]-y[m][n-1];
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
    p=(xn-x[i-1])/(x[1]-x[0]);
    fa=y[i-1][0];
    for(int m=1,n=0;m<i;m++){
        float mul=p;
        for(int z=0;z<m;z++){
            if(z==0){
                continue;
            }
            // printf("p=%f - %d = %f\n",p,z,p-z);
            mul = mul * (p+z);
            // printf("mul=%f\n",mul);
        }
        fa+=(mul*y[i-m-1][m])/fact(m);
        // printf("%f\t%f\t%f\t%f\n",(mul*y[i-m-1][m])/fact(m),mul,y[i-m-1][m],fact(m));
    }
    printf("For X=%f  Y=%f",xn,fa);
    return 0;
}