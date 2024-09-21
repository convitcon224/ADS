#include <stdio.h>
#include <math.h>

// 1 = true (yes/happened)
// 0 = false

struct pFunc
{
    float a;//coefficient
    int n;//degree
};
typedef struct pFunc pFunc;

void newTerm (pFunc *pF){
    printf("a = "); scanf("%f",&(pF->a));
    while (pF->a==0)
    {
        printf("a must be different from 0\n");
        printf("a = "); scanf("%f",&(pF->a));
    }
    printf("n = "); scanf("%d",&(pF->n));
}

void printTerm(pFunc pF){
    if (pF.a>0){
        if (pF.n==0)
            printf(" + %.2f",pF.a);
        else if (pF.n==1)
            printf(" + %.2fx",pF.a);
        else
            printf(" + %.2fx^%d",pF.a,pF.n);
    }
    else if (pF.a<0){
        if (pF.n==0)
            printf(" - %.2f",-pF.a);
        else if (pF.n==1)
            printf(" - %.2fx",-pF.a);
        else
            printf(" - %.2fx^%d",-pF.a,pF.n);
    }
}

void updateFunc(pFunc term[], int *n){
    int k; //#newterms
    printf("Number of new term(s): ");
    scanf("%d",&k);
    while (k<=0){
        printf("Number of new term(s): ");
        scanf("%d",&k);
    }
    if ((*n+k)<=100){
        for (int i=*n; i<(k+*n); i++){
            printf("Input term number %d:\n",i+1);
            newTerm(&(term[i]));
        }
        *n+=k;
    }
    else
        printf("Cannot add %d more term(s)",k);
}

void printFunc(pFunc term[], int n){
    //first term
    if (term[0].a>0){
        if (term[0].n==0)
            printf("%.2f",term[0].a);
        else if (term[0].n==1)
            printf("%.2fx",term[0].a);
        else
            printf("%.2fx^%d",term[0].a,term[0].n);
    }
    else if (term[0].a<0){
        if (term[0].n==0)
            printf("- %.2f",-term[0].a);
        else if (term[0].n==1)
            printf("- %.2fx",-term[0].a);
        else
            printf("- %.2fx^%d",-term[0].a,term[0].n);
    }
    //others terms
    for(int i=1; i<n; i++){
        printTerm(term[i]);
    }
}

void swapTerm(pFunc *p1, pFunc *p2){
    pFunc term;
    term = *p1;
    *p1 = *p2;
    *p2 = term;
}

void sortEquation(pFunc term[], int n){
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1;j++){
            if(term[j].n>term[j+1].n)
                swapTerm(&(term[j]),&(term[j+1]));
        }
    }
}

void addTerm(pFunc term[], int *k){
    int remv = *k;
    int check = 1, i = 0; // 1 = maybe can add
    for (int q=0; q<remv-1; q++){
        check = 0;
        for (i; i<remv-1; i++){
            if (term[i].n==term[i+1].n){
                term[i].a = term[i].a + term[i+1].a;
                for (int j=i+1;j<remv;j++){
                    term[j]=term[j+1];
                }
                remv--;
                check = 1;
            }
        }
        if (i=remv-2 && check==0)
            break;;
    }
    *k=remv;
}

void removeTerm(pFunc term[],int *n){
    int remv;
    printf("Term position you want to remove (1 - end): ");
    scanf("%d",&remv);
    while (remv<=0||remv>*n)
    {
        printf("Term position must be a positive integer: \n");
        printf("Term position you want to remove (1 - end): ");
        scanf("%d",&remv);
    }
    for (int i=remv-1; i<*n; i++){
        term[i]=term[i+1];
    }
    *n-=1;

}

void calWithX(pFunc term[],int n){
    float sum = 0, x;
    printf("Please input x: "); scanf("%f",&x);
    for (int i=0;i<n;i++){
        sum += term[i].a*pow(x,term[i].n);
    }
    printf("The polynomial function = %.2f when x = %.2f",sum,x);
}

int main(){
    pFunc term[100];
    int n = 0; //total terms number
    int Answer;
    char check;

        updateFunc(&(term), &n);
        sortEquation(&(term),n);
        addTerm(&(term),&n);
        printFunc(term,n);
    
    while(n!=0){
        printf("\nEnter 1 to print function\n");
        printf("Enter 2 to add more term(s)\n");
        printf("Enter 3 to remove a term\n");
        printf("Enter 4 to caculate function with specific x\n");
        printf("Enter 5 to exit\n");
        printf("Your choice: ");
        scanf("%d",&Answer);
        while (Answer>5||Answer<1)
        {
            printf("Your choice: ");
            scanf("%d",&Answer);
        }

        switch (Answer)
        {
        case 1:
            printFunc(term,n);
            break;
        case 2:
            updateFunc(&(term), &n);
            sortEquation(&(term),n);
            addTerm(&(term),&n);
            printFunc(term,n);
            break;
        case 3:
            removeTerm(&(term),&n);
            sortEquation(&(term),n);
            addTerm(&(term),&n);
            printFunc(term,n);
            break;
        case 4:
            calWithX(term,n);
            break;
        case 5:
            return 0;
        }
    }
}