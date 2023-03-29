#include<stdio.h>
int main() {
    int i,j;
    printf("Enter Number Of Equations : ");
    scanf("%d", &i);
    // i=3;
    j=i+1;
    float e[i][j];
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
    //Lower triangular Matrix
    float l[i][i];
    for(int n=0;n<i;n++){
        for(int m=0;m<i;m++){
            if(n==m){
                l[n][m]=1.0;
                continue;
            }
            l[n][m]=0.0;
        }
    }
    //Upper triangular Matrix
    for(int n=0;n<i;n++){
        if(e[n][n]==0.0 || e[n][n]==-0.0){
            printf("Mathematical Error!");
            return 0;
        }
        for(int m=n+1;m<i;m++){
            float fact = e[m][n]/e[n][n];
            //Upper triangular Matrix
            l[m][n]=fact;
            printf("Factor - %f\n", fact);
            for(int l=0;l<j-1;l++){
                e[m][l]=e[m][l]- (fact * e[n][l]);
            }
        }
    }
    printf("Upper Triangular Matrix : \n");
    for(int n=0;n<i;n++){
        for(int m=0;m<j;m++){
            printf("%f\t", e[n][m]);
        }
        printf("\n");
    }
    printf("Lower Triangular Matrix : \n");
    for(int n=0;n<i;n++){
        for(int m=0;m<i;m++){
            printf("%f\t", l[n][m]);
        }
        printf("\n");
    }
    //Finding Y
    float v[i],s;
    j=j-1;
    for(int x=0;x<i;x++){
        v[x]=0.0;
    }
    for(int x=0,y=j;x<i;x++){
        v[x]=1;
        s=0.0;
        for(int y=0,b=0;y<j;y++,b++){
            if(y==x){
                continue;
            }
            s=s + v[b]*l[x][y];
        }
        e[x][y]=e[x][y]-s;
        v[x] = e[x][y]/v[x];
    }
    printf("Solutions Of Y : \n");
    for(int n=0,a=0;n<i;n++,a++){
        printf("Y%d = %f\n", n+1, v[a]);
    }
    // Finding X
    float vi[i];
    for(int x=0;x<i;x++){
        vi[x]=0.0;
    }
    for(int x=i-1,y=j-1;x>=0;x--,y--){
        vi[x]=1;
        s=0.0;
        for(int y=j-1,b=i-1;y>=0;y--,b--){
            if(y==x){
                continue;
            }
            s=s + vi[b]*e[x][y];
        }
        v[y]=v[y]-s;
        if(e[x][x]==0.0 || e[x][x]==-0.0){
            vi[x]=0.0;
            continue;
        }
        vi[x] = v[x]/e[x][x];
    }
    printf("Solutions X : \n");
    for(int n=0,a=0;n<i;n++,a++){
        printf("X%d = %f\n", n+1, vi[a]);
    }
	return 0;
}