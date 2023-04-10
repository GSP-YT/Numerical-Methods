#include<stdio.h>
#include<math.h>
float fun(float x,float y){
    float f= -2*y + x*x*x/exp(2*x) ;
    return f;
}
int main(){
    float h=0.1;
    float x[4]={0,0.1,0.2,0.3};
    float y[4]={1};

    for(int i=1;i<=4;i++){
        printf("X%d=%f , Y%d=%f\n",i-1,x[i-1],i-1,y[i-1]);
        y[i]=y[i-1]+ h*fun(x[i-1],y[i-1]);
    }
    return 0;
}