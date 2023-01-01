#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>//Alphanumeric identification library

struct stack
{
int size; int top;
 
char *arr;
};

void push(struct stack *ptr, char data)
{
if (ptr->top < ptr->size - 1)	{ ptr->top++;
ptr->arr[ptr->top] = data;
}
}

char pop(struct stack *ptr)
{
if (ptr->top > -1) {
char data = ptr->arr[ptr->top]; ptr->top--;
return data;
}
}

int precedence(char x){ if (x == '(')
return 0;
if (x == '+' || x == '-') return 1;
if (x == '*' || x == '/') return 2;
return 0;
}

void main()
{
char inf[100],*ptr; printf("Enter Infix : "); scanf("%s", inf);
ptr = inf; int data;

struct stack *s = (struct stack *)malloc(sizeof(struct stack)); s->size = 50;
s->top = -1;
s->arr = (char *)malloc(s->size * sizeof(char));

printf("Required Postfix : "); while(*ptr!='\0'){
if (isalnum(*ptr)) printf("%c", *ptr);

else if (*ptr=='(') push(s,*ptr);

else if (*ptr==')'){
while ((data = pop(s))!='(') printf("%c", data); //(f-e)/c*b+a
 
}

else{
while (precedence(s->arr[s->top])>=precedence(*ptr)) printf("%c", pop(s));
push(s, *ptr);
}
ptr++;
}

while(s->top!=-1) printf("%c", pop(s));
}
