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
    float f=y[0]+y[n];
    float ev=0,od=0;
    for(int m=1;m<n;m++){
        if(m%2==0){
            ev+=y[m];
        }
        else {
            od+=y[m];
        }
    }
    float fa=(f+(2*ev)+(4*od))*(h/3);
    printf("f=%f",fa);
    return 0;
}