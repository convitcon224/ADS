#include <stdio.h>
#include <math.h>



//ITERATIONS
int n = 10;

void count(int i,double *x, double *y){
    double fx,fy;


    //INPUT FUNCTION HERE
    fx = -3-*y+*z;
    fy = (2-6*(*x)-2*(*z))/2;

    printf("%d. x = %lf     y= %lf\n",i,fx,fy);
    *x=fx;
    *y=fy;
}

int main(){
    double x,y;
    printf("x = ");
    scanf("%lf",&x);
    printf("y = ");
    scanf("%lf",&y);


    for(int i=1;i<=n;i++){
        count(i,&x,&y);
    }
    
}