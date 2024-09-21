#include <stdio.h>
#include <math.h>




//ITERATIONS
int n = 10;

void count(double x, double y, double z){
    for (int i = 1; i<=n; i++){
        
        
        //INPUT FUNCTION HERE
        x = (11-2*y+z)/10;
        y = (-7+3*x-2*z)/(-5);
        z = (21-x-y)/6;
        printf("%d. x = %lf     y= %lf      z = %lf\n",i,x,y,z);
    }
}

int main(){
    double x,y,z;
    printf("x = ");
    scanf("%lf",&x);
    printf("y = ");
    scanf("%lf",&y);
    printf("z = ");
    scanf("%lf",&z);
    count(x,y,z);
}