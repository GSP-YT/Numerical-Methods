#include<stdio.h>

float fun(float x){
    float f = x*x-3;
    return f;
}
int main (){
    float a,b,t,fa,fb,ft;
    for(a=0;;a++){
        fa=fun(a);
        if(fa<0){
            // printf("%d", fa);
            break;
        }
    }
    for(b=0;;b++){
        fb=fun(b);
        if(fb>0){
            // printf("%d", fb);
            break;
        }
    }
    t=(a+b)/2.0;
    ft=fun(t);
    // printf("%d", ft);
    printf("s.i. No.\t");
    printf("a\t\t");
    printf("b\t\t");
    printf("t\t\t");
    printf("fa\t\t");
    printf("fb\t\t");
    printf("ft\t\t");
    int i=0;
    while(i>=0){
        printf("\nIteration %d\t", i);
        printf("%f\t", a);
        printf("%f\t", b);
        printf("%f\t", t);
        printf("%f\t", fa);
        printf("%f\t", fb);
        printf("%f\t", ft);
        if(ft<0){
            a=t;
            fa=fun(a);
        }
        else if(ft>0){
            b=t;
            fb=fun(b);
        }
        t=(a+b)/2.0;
        ft=fun(t);
        if(ft>0){
            if(ft<0.0001)
            break;
        }
        else{
            if(ft>-0.0001)
            break;
        }
        i++;
    }

    return 0;
}