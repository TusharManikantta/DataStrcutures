//stack using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* top=NULL;
void push(){
	int value;
	printf("enter the value you want to push into the stack\n");
	scanf("%d",&value);
	struct node* newnode=NULL;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	if(top==NULL) 
    newnode->next=NULL;
	else 
    newnode->next=top;
	top=newnode;
	printf("node is inserted\n");
}
void pop(){
	if(top==NULL) 
    printf("empty stack\n");
	else{
		struct node*temp=top;
		temp->data=top->data;
		top=top->next;
		free(temp);
	}
}
void display(){
    if(top==NULL) printf("empty stack....no elements to display\n");
    else{
    	struct node*temp=top;
    	while(temp->next!=NULL){
    		printf("%d->",temp->data);
    		temp=temp->next;
		}
		printf("%d",temp->data);
	}
}
int main(){
	int choice=1;
	int opt;
	while(choice){
		printf("Menu list for stack implementation using linked list\n1.push()\n2.pop()\n3.display()\n4.exit\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			break;
			default:printf("invalid entry...\n");
			break;
		}
		printf("do you want to continue the process(1-Yes/0-No)\n");
		scanf("%d",&choice);
	}
}
