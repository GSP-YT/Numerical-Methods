#include<stdio.h>
#include<math.h>
int main (){
    int f=3+1;
    // int a[f],x[f],n[f];
    float a[4]={1,-10,0,6};
    int n[4]={3,2,1,0};
    for(;;){
        for(int j=0;j<f;j++){
            if(a[j]==0){
                continue;
            }
            printf("%f X",a[j]);
            if(n[j]>0){
                printf("^%d",n[j]);
            }
            printf("\t");
        }
        printf("\n");
        for(int j=0;j<f;j++){
            a[j]*=n[j];
            n[j]--;
        } 
        if(n[0]==-1){
            break;
        }
    }
    return 0;
}