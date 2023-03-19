#include<stdio.h>
int main(){
    int i,j;
    printf("Enter Number Of Equations : ");
    scanf("%d", &i);
    j=i+1;
    float e[i][j];
    // float e[3][4]={{9.0,5.0,3.0,4.0},{3.0,7.0,1.0,5.0},{3.0,0.0,5.0,8.0}};
    // float e[3][4]={9, 1 ,2 ,3 ,4 , 5 , 6 , 7 , 8 , 9 , 10 , 11};
    for(int n=0;n<i;n++){
        printf("Enter Equation %d : \n", n+1);
        for(int m=0;m<j;m++){
            printf("Enter Coefficient Of x%d : ", m+1);
            scanf("%f", &e[n][m]);
        }
    }
    printf("Entered Equations : \n");
    for(int n=0;n<i;n++){
        for(int m=0;m<j;m++){
            printf("%f\t", e[n][m]);
        }
        printf("\n");
    }
    //Forward Elimination
    for(int n=0;n<i;n++){
        if(e[n][n]==0.0 || e[n][n]==-0.0){
            printf("Mathematical Error!");
            return 0;
        }
        for(int m=n+1;m<i;m++){
            float fact = e[m][n]/e[n][n];
            printf("Factor - %f\n", fact);
            for(int l=0;l<j;l++){
                e[m][l]=e[m][l]- (fact * e[n][l]);
            }
        }
    }
    printf("Equations After Forward Elimination : \n");
    for(int n=0;n<i;n++){
        for(int m=0;m<j;m++){
            printf("%f\t", e[n][m]);
        }
        printf("\n");
    }
    //Backward Substitution
    float v[i],s;
    for(int x=0;x<i;x++){
        v[x]=0.0;
    }
    for(int x=i-1,a=i-1,y=j-1;x>=0;x--,a--){
        v[a]=1;
        s=0.0;
        for(int y=j-2,b=i-1;y>=0;y--,b--){
            if(y==x){
                continue;
            }
            s=s + v[b]*e[x][y];
        }
        e[x][y]=e[x][y]-s;
        if(e[x][x]==0.0 || e[x][x]==-0.0){
            v[a]=0.0;
            continue;
        }
        v[a] = e[x][y]/e[x][x];
    }
    printf("Solutions After Backward Substitution : \n");
    for(int n=0,a=0;n<i;n++,a++){
        printf("x%d = %f\n", n+1, v[a]);
    }
    return 0;
}

