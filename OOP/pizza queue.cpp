// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct Pizza{
    int id,qty;
    char name[20];
    char address[30];
};struct Pizza p[3];

int front=0;
int rear=0;
int is_full(){
    if(front==rear+1){
        return -1;
    }
    else{
        return 0;
    }
}
void place_order(){
    if(is_full()==0){
        rear++;
        p[rear].id=id++;
        printf("\nEnter name:");
        scanf("%s",p[rear].name);
        printf("\nEnter address:");
        scanf("%s",p[rear].address);
        printf("\nEnter quantity:");
        scanf("%d",&p[rear].qty);
        
    }
    else{
        printf("\nOrder is full!!");
      }
}
int is_empty(){
    if(front==rear){
        return -1;
    }
    else{
        return 0;
    }
}
void dispatch_order(){
    if(is_empty()==0){
        front++;
    }
}
void display(){
    for(int i=front+1;i<=rear;i++){
        printf("\nID: %d",p[i].id);
        printf("\nNAME: %s",p[i].name);
        printf("\nADDRESS: %s",p[i].address);
        printf("\nQUANTITY: %d",p[i].qty);
    }
}
int main() {
    // Write C++ code here
    int i;
    Pizza p[100];
    cout<<"Menu:\n";
    cout<<"1.Place Order\n";
    cout<<"2.Dispatch Order\n";
    cout<<"3.Display Order\n";
    cout<<"4.Exit\n";
    cout<<"Enter your choice:";
    cin>>i;
    while(i!=4){
    switch(i){
    case 1: place_order();
    break;
    case 2: dispatch_order();
    break;
    case 3: display();
    break;
    case 4:
    break;
    cout<<"\nEnter your choice:";

    cin>>i;
    }
}
    return 0;
}
