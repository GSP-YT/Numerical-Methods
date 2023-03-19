#include<stdio.h>
#include<math.h>
float fun( float x) {
    // float f =((x*x)/ (float) exp(x/2.0)) - 1;
    // float f = (1/exp(x)) - x;
    float f = (x*x*x) - (5*x) + 1;
    return f;
}
float x(float x0,float x1,float fx0,float fx1){
    float x = x1 - (((x0-x1)*fx1)/(fx0-fx1));
    return x;
}
int main(){
    float a,b,x0=0,x1=1,fx0,fx1,x2,fx2;
    // printf("Enter Low Range : ");
    // scanf("%f", &a);
    // printf("Enter High Range : ");
    // scanf("%f", &b);
    // x0=x(a,b);
    printf("x0\t\t");
    printf("fx0\t\t");
    printf("x1\t\t");
    printf("error\t\t");
    printf("root\n");
    for(int n=0;;n++){
        // x0=a;
        printf("%f\t", x0);
        fx0=fun(x0);
        printf("%f\t", fx0);
        // x1=b;
        printf("%f\t", x1);
        fx1=fun(x1);
        printf("%f\t", fx1);
        x2=x(x0,x1,fx0,fx1);
        printf("%f\n", x2);
        if(fx1>0){
            if(fx1<0.001)
            break;
        }
        else{
            if(fx1>-0.001)
            break;
        }
        x0=x1;
        x1=x2;

    }

    return 0;
}
