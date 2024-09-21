#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Products
int macbook = 300;
int iphone = 500;
int watch = 700;

//Customers bought
struct history{
    int index;
    int mac, phone, wat;
    struct history *next;
};

typedef struct history his;


//Queue
struct customer{
    struct customer *next;
};

typedef struct customer cus;

struct queue{
    cus *back, *front;
    int size;
};

typedef struct queue queue;


//Random quantity
int GetRandom(int min,int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

int getMin(int a, int b){
    if (a<b)
        return a;
    else
        return b;
}

void init(queue *q){
    q->size = 0;
    q->back = q->front = NULL;
}

//Customer's history
void saveHistory(int m, int p, int w, his **hi, int in){
    his *h = (his *)malloc(sizeof(his));
    h->index = in;
    h->mac = m;
    h->phone = p;
    h->wat = w;
    h->next = *hi;
    *hi = h;
}


//Print customers and products information
void display(queue cus, his left){
    printf("\n%d macbook(s) left\n",macbook);
    printf("%d iphone(s) left\n",iphone);
    printf("%d watch(s) left\n",watch);
    printf("Number of customers queuing: %d\n", cus.size);
    printf("Number of customers who have left: %d\n", left.index);
}

//More people queue
void enqueue(queue *q){
    cus *p = (cus *)malloc(sizeof(cus));
    p->next = NULL;
    if (q->front == NULL){
        q->back = q->front = p;
    }
    else{
        p->next = q->back;
        q->back = p;
    }
    q->size += 1;
}

//Leave line after buying
void dequeue(queue *q){
    if (q->size == 0)
        return;
    else{
        if (q->size == 1){
            q->back = q->front = NULL;
            q->size -= 1;
        }
        else{
            cus *p = q->back;
            while (q->front != p->next)
                p = p->next;
            q->front = p;
            p->next = NULL;
            q->size -= 1;
        }
    }
}

void buy(queue *q, his **h, int *total){
    int b_m=0, b_i=0, b_w=0; //Cus buy
    int m,i,w; //Quantity can buy

    //Number of macbook can buy
    if (macbook>0)
        m = GetRandom(1,getMin(2,macbook));
    else{
        printf("Macbook is out of stock\n");
        m=0;
    }
    
    //Number of iphone can buy
    if (iphone>0)
        i = GetRandom(1,getMin(3,iphone));
    else{
        printf("Iphone is out of stock\n");
        i = 0;
    }

    //Number of watch can buy
    if (watch>0)
        w = GetRandom(1,getMin(4,watch));
    else{
        printf("Watch is out of stock\n");
        w=0;
    }

    //Buy products
    printf("You can buy %d macbook(s), %d iphone(s), %d watch(s)\n",m,i,w);
    //Buy macbook
    if(m!=0){
        printf("How many macbook(s) do you want to buy? ");
        scanf("%d",&b_m);
        while (b_m>m||b_m<0)
        {
            printf("You can buy %d macbook(s)\n",m);
            printf("How many macbook(s) do you want to buy? ");
            scanf("%d",&b_m);
        }      
        if(b_m<=m && b_m>=0){
            printf("Purchase success\n");
            printf("You bought %d macbook(s)\n",b_m);
            macbook -= b_m;
        }
    }

    //Buy iphone
    if(i!=0){
        printf("How many iphone(s) do you want to buy? ");
        scanf("%d",&b_i);
        while (b_i>i||b_i<0)
        {
            printf("You can buy %d iphone(s)\n",i);
            printf("How many iphone(s) do you want to buy? ");
            scanf("%d",&b_i);
        }      
        if(b_i<=i && b_i>=0){
            printf("Purchase success\n");
            printf("You bought %d iphone(s)\n",b_i);
            iphone -= b_i;
        }
    }
    
    //Buy watch
    if(w!=0){
        printf("How many watch(s) do you want to buy? ");
        scanf("%d",&b_w);
        while (b_w>w||b_w<0)
        {
            printf("You can buy %d watch(s)\n",w);
            printf("How many watch(s) do you want to buy? ");
            scanf("%d",&b_w);
        }      
        if(b_w<=w && b_w>=0){
            printf("Purchase success\n");
            printf("You bought %d watch(s)\n",b_w);
            watch -= b_w;
        }
    }

    //Save information
    *total += 1;
    saveHistory(b_m,b_i,b_w,h,*total);
    dequeue(q);
}

void printHistory(his *h, int index){
    if (index == 0){
        printf("No history yet");
        return;
    }
    else{
        while (h!=NULL)
        {
            if(h->mac==0&&h->phone==0&&h->wat==0)
                printf("\nCustomer number %d buy nothing\n",h->index);
            else{
                printf("\nCustomer number %d buys:\n",h->index);
                if(h->mac > 0)
                    printf("    %d macbook(s)\n",h->mac);
                if(h->phone > 0)
                    printf("    %d iphone(s)\n",h->phone);
                if(h->wat > 0)
                    printf("    %d watch(s)\n",h->wat);
            }
            h=h->next;
        }
    }
    return;
}

void updateCustomer(queue *s, int max){
    int k = 0; //Number of new customers
    printf("Number of customer(s) enter queue: ");
    scanf("%d",&k);
    while (k<0||k+(s->size)>max){
        printf("There is only room for %d more people\n",max-(s->size));
        printf("Number of customer(s) enter queue: ");
        scanf("%d",&k);
    }
    for (int i=1; i<=k; i++){
        enqueue(s);
    }
    return;
}

int main(){
    int index = 0; //#Cus
    his *head = NULL; //History first node
    queue customer;
    int max = 200; //Line capacity
    int choice = 22042000;

    init(&customer);
    updateCustomer(&customer,max);

    //Loop
    while (customer.size>0){
        printf("\nEnter 1 for the next customer to buy\n");
        printf("Enter 2 to print all buying history\n");
        printf("Enter 3 to update queue\n");
        printf("Enter 4 to display information\n");
        printf("Enter 5 to exit\n");
        printf("Your choice: ");
        scanf("%d",&choice);
        while (choice<1||choice>5)
        {
            printf("Your choice: ");
            scanf("%d",&choice);
        }

        switch (choice)
        {
        case 1:
            buy(&customer,&head,&index);
            break;
        case 2:
            printHistory(head, index);
            break;
        case 3:
            updateCustomer(&customer,max);
            break;
        case 4:
            if(index==0){
                printf("\n%d macbook(s) left\n",macbook);
                printf("%d iphone(s) left\n",iphone);
                printf("%d watch(s) left\n",watch);
                printf("Number of customers queuing: %d\n", customer.size);
                printf("Number of customers who have left: 0\n");
            }
            else
                display(customer,*head);
            break;
        case 5:
            return 0;
        }   
    }
    return 0;
}