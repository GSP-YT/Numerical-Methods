#include<stdio.h>

float fun(float x){
    float f = x*x-3;
    return f;
}
float fund(float x){
    float f = 2*x;
    return f;
}
float xone(float x0){
    float f,fx0,fx0d;
    fx0= fun(x0);
    fx0d= fund(x0);
    // printf("%f\t", fx0);
    // printf("%f\t", fx0d);
    f= x0 - (fx0/fx0d);
    // printf("%f\t", f);
    return f;
}

int main (){
    float x0,x1,fx0,fx1;
    for(x0=0;;x0++){
        fx0=fun(x0);
        if(fx0>0){
            x0--;
            break;
        }
    }
    x1=x0;
    // printf("%f\t", x0);
    // fx0=fun(x0);
    // printf("%f\t", fx0);
    // x1= xone(x0);
    // printf("%f\t", x1);
    // fx1= fun(x1);
    // printf("%f\n", fx1);
    printf("s.i. No.\t");
    printf("x0\t\t");
    printf("fx0\t\t");
    printf("x1\t\t");
    printf("fx1\t\t");
    for(int i=0;;i++){
        x0=x1;
        fx0=fun(x0);
        x1= xone(x0);
        fx1= fun(x1);
        printf("\nIteration %d\t", i);
        printf("%f\t", x0);
        printf("%f\t", fx0);
        printf("%f\t", x1);
        printf("%f\t", fx1);
        if(fx1>0){
            if(fx1<0.0001)
            break;
        }
        else{
            if(fx1>-0.0001)
            break;
        }
    }

    return 0;
}