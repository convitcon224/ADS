#include <stdio.h>
#include <math.h>



//ITERATIONS
int n = 10;

void count(int i,double *x, double *y, double *z, double*t){
    double fx,fy,fz,ft;


    //INPUT FUNCTION HERE
    fx = (6+(*y)-2*(*z))/10;
    fy = (25+*x+*z-3*(*t))/11;
    fz = (-11-2*(*x)+*y+*t)/10;
    ft = (15-3*(*y)+*z)/8;
    printf("%d. x = %lf     y= %lf      z = %lf     t=%lf\n",i,fx,fy,fz,ft);
    *x=fx;
    *y=fy;
    *z=fz;
    *t=ft;
}

int main(){
    double x,y,z,t;
    printf("x = ");
    scanf("%lf",&x);
    printf("y = ");
    scanf("%lf",&y);
    printf("z = ");
    scanf("%lf",&z);
    printf("t = ");
    scanf("%lf",&t);

    for(int i=1;i<=n;i++){
        count(i,&x,&y,&z,&t);
    }
    
}