#include <stdio.h>
#include <math.h>



//ITERATIONS
int n = 10;

void count(int i,double *x, double *y, double *z){
    double fx,fy,fz;


    //INPUT FUNCTION HERE
    fx = -3-*y+*z;
    fy = (2-6*(*x)-2*(*z))/2;
    fz = 1+3*(*x)-4*(*y);
    printf("%d. x = %lf     y= %lf      z = %lf\n",i,fx,fy,fz);
    *x=fx;
    *y=fy;
    *z=fz;
}

int main(){
    double x,y,z,z2;
    printf("x = ");
    scanf("%lf",&x);
    printf("y = ");
    scanf("%lf",&y);
    printf("z = ");
    scanf("%lf",&z);

    for(int i=1;i<=n;i++){
        count(i,&x,&y,&z);
    }
    
}