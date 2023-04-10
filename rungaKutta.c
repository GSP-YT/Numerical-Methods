#include<stdio.h>
#include<math.h>
float fun(float x,float y){
    // float f= -2*y + x*x*x/exp(2*x) ;
    // float f= y-(2*x*x)+1;
    float f= x*x + y*y;
    // float f= 2*x + 3*y*y;
    // float f= (y-x)/(y+x);
    return f;
}
int main(){
    float h=0.05;
    int n=1;
    float x[n],y[n],k[n];
    x[0]=1;
    y[0]=1.2;
    printf("Xn\t\tK1\t\tK2\t\tK3\t\tK4\t\tYn+1\n");
    for(int i=0;i<n;i++){
        k[0]=h*fun(x[i],y[i]);
        k[1]=h*fun(x[i]+(h/2),y[i]+(k[0]/2));
        k[2]=h*fun(x[i]+(h/2),y[i]+(k[1]/2));
        k[3]=h*fun(x[i]+h,y[i]+k[2]);
        x[i+1]=x[i]+h;
        y[i+1]=y[i]+ (k[0]+ (2*k[1]) + (2*k[2]) + k[3])/6;
        printf("%f\t%f\t%f\t%f\t%f\t%f\n",x[i],k[0],k[1],k[2],k[3],y[i+1]);
    }
    return 0;
}