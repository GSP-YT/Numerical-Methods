#include<stdio.h>
#include<math.h>
float fun(float x,float y){
    // float f= -2*y + x*x*x/exp(2*x) ;
    float f= y-(2*x*x)+1;
    return f;
}
int main(){
    float h=0.2;
    int xn=1;
    int n=(float)(xn-0)/h;
    float x[n],yp[n],yc[n];
    x[0]=0;
    yp[0]=0.5;
    printf("Xn\t\tYn\t\tXn+1\t\tYn+1,p\t\tYn+1,c\n");
    for(int i=1;i<=n+1;i++){
        x[i]=x[i-1]+h;
        printf("%f\t%f\t",x[i-1],yp[i-1]);
        yp[i]=yp[i-1]+ h*fun(x[i-1],yp[i-1]);
        printf("%f\t%f\t",x[i],yp[i]);
        yc[i]=yp[i-1]+ (h/2)*(fun(x[i-1],yp[i-1]) + fun(x[i],yp[i]));
        printf("%f\n",yc[i]);
        yp[i]=yc[i];
    }
    return 0;
}