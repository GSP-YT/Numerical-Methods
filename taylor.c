#include<stdio.h>
#include<math.h>
float fact(float x){
    if(x==0){
        return 1;
    }
    float f=x*fact(x-1);
    return f;
}
int main (){
    int e=3+1,x=3,c=1;
    // int a[f],x[f],n[f];
    float a[4]={1,-10,0,6},f[e];
    int n[4]={3,2,1,0};
    for(int i=0;;i++){
        // for(int j=0;j<e;j++){
        //     printf("%f X^%d\t",a[j],n[j]);
        // }
        // printf("\n");
        f[i]=0;
        //finding f' of x
        for(int j=0;j<e;j++){
            if(n[j]>=0||a[j]>0){
                f[i]+=a[j]*pow(x,n[j]);
            }
            else{
                break;
            }
        }
        //stoping condition
        if(n[0]==0){
            break;
        }
        //finding derivative
        for(int j=0;j<e;j++){
            a[j]*=n[j];
            n[j]--;
        } 
    }
    printf("Taylor Series = \n");
    // float z=0,s=c-x;
    for(int j=0;j<e;j++){
        // z+=(f[j]/fact(j))*pow(s,j);
        printf("%f (X-%d)^%d\t",f[j]/fact(j),x,j);
    }
    // printf("X==%f",z);
    return 0;
}