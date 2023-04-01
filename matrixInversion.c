#include<stdio.h>
int main() {
    int i,j;
    // printf("Enter Number Of Equations : ");
    // scanf("%d", &i);
    i=3;
    j=i+1;
    float v[i],s,vi[i],x[i];
    // float e[i][j];
    // float e[3][4]={9, 1 ,2 ,3 ,4 , 5 , 6 , 7 , 8 , 9 , 10 , 11};
    // float e[3][4]={3, -0.1, -0.2,0,
    //                 0.1, 7, -0.3,0,
    //                 0.3, -0.2, 10,0};
    float e[3][4]={2,3,3,5,
                    1,-2,1,-4,
                    3,-1,-2,3};
    // for(int n=0;n<i;n++){
    //     printf("Enter Equation %d : \n", n+1);
    //     for(int m=0;m<j;m++){
    //         printf("Enter Coefficient Of x%d : ", m+1);
    //         scanf("%f", &e[n][m]);
    //     }
    // }
    printf("Entered Equations : \n");
    for(int n=0;n<i;n++){
        for(int m=0;m<j;m++){
            printf("%f\t", e[n][m]);
        }
        printf("\n");
    }
    //Making Identity For Lower For triangular Matrix
    float l[i][i],id[i][i],inv[i][i];
    for(int n=0;n<i;n++){
        for(int m=0;m<i;m++){
            if(n==m){
                id[n][m]=l[n][m]=1.0;
                continue;
            }
            id[n][m]=l[n][m]=0.0;
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
            //Lower triangular Matrix
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
    for(int z=0;z<i;z++){
        x[z]=vi[z]=v[z]=0.0;
    }
    for(int n=0,k=i-1;n<i;n++,k--){
        //Finding Y
        for(int x=0,y=i;x<i;x++){
            v[x]=1;
            s=0.0;
            for(int y=0,b=0;y<i;y++,b++){
                if(y==x){
                    continue;
                }
                s=s + v[b]*l[x][y];
            }
            id[x][n]=id[x][n]-s;
            v[x] = id[x][n]/v[x];
            // printf("V= %f\t",v[x]);
        }
        // Finding Inverse by finding X
        for(int x=i-1,y=i-1;x>=0;x--,y--){
            vi[x]=1;
            s=0.0;
            for(int y=i-1,b=i-1;y>=0;y--,b--){
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
            // printf("Vi= %f\t",vi[x]);
            inv[x][n]=vi[x];
        }
    }
    printf("Inverse matrix : \n");
    for(int n=0;n<i;n++){
        for(int m=0;m<i;m++){
            printf("%f\t", inv[n][m]);
        }
        printf("\n");
    }
    //Calculating X
    for(int n=0,z=i;n<i;n++){
        for(int m=0;m<i;m++){
            x[n]+= inv[n][m]*e[m][z];
        }
    }
    printf("Solutions : \n");
    for(int n=0,a=0;n<i;n++,a++){
        printf("X%d = %f\n", n+1, x[a]);
    }
	return 0;
}