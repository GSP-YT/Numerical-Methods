#include<stdio.h>
float fun(float x){
    float f = 1/(1+x*x);
    return f;
}
int main (){
    //enter range
    int a=0,b=6,n=6;
    float y[n+1],x[n+1];
    //calculating 'h'
    float h= (float) (b-a)/(float)n;
    //calculating trapezoid
    for(int m=0;m<=n;m++){
        if(m==0){      
            x[m]=0;
            continue;
        }
        x[m]=x[m-1]+h;
    }
    printf("X\t\tY\n");
    for(int m=a;m<=n;m++){
        y[m]=fun(x[m]);
        printf("%f\t%f\n",x[m],y[m]);
    }
    float sum=0;
    for(int m=0;m<n;m+=6){
        sum+=y[0+m]+(5*y[1+m])+y[2+m]+(6*y[3+m])+y[4+m]+(5*y[5+m])+y[6+m];
    }
    float fa=(sum)*(3*h/10);
    printf("f=%f",fa);
    return 0;
}