#include <stdio.h>
#include <math.h>
//The complexity of my program: O(n^6)
long int Result(int p, int q, int r){
    return p*q*r;
}
int main(){
    int n,p,q,r;
    int check = 0;
    printf("Input n: ");
    scanf ("%d",&n);
    //First prime number
    for (int i=2;i<=n;i++){
	    for (int j=2; j<i; j++){
            if(i%j==0)
                break;
            else if(j==i-1){
                p=i;
                //Second prime number
                for (int k=2;k<i;k++){
                    for (int l=2;l<k;l++){
                        if(k%l==0)
                            break;
                        else if(l==k-1){
                            q=k;
                            //Prime number 2
                            r=2;
                            if (r==2 && p>q && q>r){
                                //Check if n is sphenic
                                if (n==Result(p,q,r)){
                                    printf("%d is sphenic",n);
                                    check = 1;
                                    return 0;
                                }
                            }
                            //Third prime number
                            for (int m=2;m<i;m++){
                                for (int n=2;n<m;n++){
                                    if (m%n==0){
                                        break;
                                    }
                                    else if (n==m-1){
                                        r=m;
                                        if (p>q && q>r)
                                        {
                                            //Check if n is sphenic
                                            if (n==Result(p,q,r) && check==0){
                                            printf("%d is sphenic",n);
                                            check = 1;
                                            return 0;
                                            }
                                        }    
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    //n is not sphenic
    if (check == 0)
    {
        printf("%d is not sphenic",n);
    }
    
    return 0;
}