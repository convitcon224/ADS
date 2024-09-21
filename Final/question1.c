#include <stdio.h>
#include <math.h>


/*Pseudo code
    int array[12]
    function pyTrip(a,b,c){
        if (a^2+b^2=c^2)
            print("a,b,c")
        if (a=array[9] and b = array[10] and c=array[11])
            return 0
        if(c!=array[11]){
            pytrip(a,b,array[+1])
        }
        else if(b!=array[10]){
            pytrip(a,array[+1],array[+2])
        }
        else if(a!=array[9]){
            pytrip(array[+1],array[+2],array[+3])
        }
    }
*/

//Complexity:
//Best scenario: O(n^3)
//Average: O(n^3)
//Worst scenario: O(n^3)
//Because we always have to check all numbers in the list

int i=0,j=1,k=2;
int Array[12] = {4,15,28,45,40,9,53,41,8,17,3,5};

int pyTrip(int a,int b,int c){
    if(pow(a,2)+pow(b,2)==pow(c,2)){
        printf("(%d,%d,%d)\n",a,b,c);
    }

    if(i==9&&j==10&&k==11){
        return 0;
    }

    if(k!=11){
        k+=1;
        pyTrip(a,b,Array[k]);
    }
    else if(k==11 && j!=10){
        j+=1;
        k=j+1;
        pyTrip(a,Array[j],Array[j+1]);
    }
    else if(i!=9 && j==10){
        i+=1;
        j=i+1;
        k=j+1;
        pyTrip(Array[i],Array[i+1],Array[i+2]);
    }
}

void swapTerm(int *a, int *b){
    int term;
    term = *a;
    *a = *b;
    *b = term;
}

int main(){
    for (int p=0;p<11;p++){
        for(int u=0;u<11;u++){
            if(Array[u]>Array[u+1])
                swapTerm(&Array[u],&Array[u+1]);
        }
    }

    for(int r=0;r<12;r++){
        printf("%d ",Array[r]);
    }
    printf("\n");

    pyTrip(Array[i],Array[j],Array[k]);
}