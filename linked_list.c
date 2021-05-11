#include<stdio.h>
#include<stdlib.h>


typedef struct node{
int value;
struct node *NEXT;
}node;
node *FIRST=NULL;
node *LAST=NULL;

void insert(int ele){
node *ptr=(node *)malloc(sizeof(node));
ptr->value=ele;
ptr->NEXT=NULL;


if(FIRST==NULL){
FIRST=ptr;
LAST=ptr;

}
else{
        LAST->NEXT=ptr;
    LAST=ptr;
LAST->NEXT=NULL;

}
printf("first is %d and last is %d",FIRST->value,LAST->value);
printf("\n");
}
void print(){
node *ptr;
ptr=FIRST;
if(FIRST==NULL){
    printf("the list is empty\n");
}
else{
for(ptr=FIRST;ptr!=LAST;ptr=ptr->NEXT){
    printf("%d ", ptr->value);
}
printf("%d\n", LAST->value);
}
}

node * search(int ele){
node *temp;
node *count=NULL;
for(temp=FIRST;temp!=LAST;temp=temp->NEXT){
    if(temp->value==ele){
        //printf("element present in list\n");
        count=temp;
    }
}
if(LAST->value==ele)
{

    //printf("element is present in the list\n");
    count=LAST;

}
return count;

}

void delete_elem(int ele){
node *a = search(ele);
if(a==NULL){
    printf("the node doesn't exist\n");
}
else if(a==FIRST && FIRST==LAST){

    FIRST=NULL;
    LAST=NULL;

}
else if(a==FIRST){
    FIRST=a->NEXT;


}

else{
    node *b;
    for(b=FIRST; b->NEXT!=a;b=b->NEXT){
        ;
    }

    if(a==LAST){

        LAST=b;

    }
    else{
        b->NEXT=a->NEXT;
    a->NEXT=NULL;
    }
printf("node deleted\n");
}

}
void main(){
    while(1){
printf("enter 1 to insert an element\n");
printf("enter 2 to search an element\n");

printf("enter 3 to exit\n");
printf("enter 4 to delete an element\n");
printf("enter 5 to print\n");
int choice;
scanf("%d",&choice);
switch(choice){
case 1: printf("enter element\n");

int b;
scanf("%d",&b);

insert(b);
break;

case 2:
    printf("enter the element to be searched\n");
    int ele;
    scanf("%d",&ele);
    node *p = search(ele);
    if(p==NULL){
        printf("element is not present in the list\n");
    }
    else{
        printf("element is present in the list\n");
    }
    break;
case 3:
    exit(1);
case 4:
    printf("enter the element to be deleted\n");
    int del;
    scanf("%d",&del);
    delete_elem(del);
    break;
case 5:
    print();
    break;
    }
    }
}
