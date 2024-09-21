#include <stdio.h>
#include <math.h>


//INTERATIONS
int o=10;
float n = 1.2; //Lan

void count(double x, double y){
    double fx,fy;
    for (int i=1;i<o;i++){
        fx = (8+2*y)/10;
        fx = o*fx + (1-o)*x;
        fy = (9+3*x)/12;
        fx = o*fy + (1-o)*y;
        printf("x = %lf     y = %lf\n",fx,fy);
        x = fx;
        y = fy;
    }
}

int main(){
    double x,y;
    printf("x = ");
    scanf("%lf",&x);
    printf("y = ");
    scanf("%lf",&y);
    count(x,y);
}