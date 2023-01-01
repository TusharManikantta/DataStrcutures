#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h> //Alphanumeric identification library #include <string.h>

struct stack
{
int size; int top; char *arr;
 
};

void push(struct stack *ptr, char data)
{
if (ptr->top < ptr->size - 1)
{
ptr->top++;
ptr->arr[ptr->top] = data;
}
}

char pop(struct stack *ptr)
{
if (ptr->top > -1)
{
char data = ptr->arr[ptr->top]; ptr->top--;
return data;
}
}

int precedence(char x)
{
if (x == '(') return 0;
if (x == '+' || x == '-') return 1;
if (x == '*' || x == '/') return 2;
return 0;
}

void main()
{
char inf[100], *ptr, pre[100]; printf("Enter Infix : "); scanf("%s", inf);

int i, j,l,data; l = strlen(inf); strrev(inf);

for (i = 0; i < l;i++){ if (inf[i]=='(')
inf[i] = ')';
else if (inf[i] == ')')
inf[i] = '(';
}

int k = 0; ptr = inf;

struct stack *s = (struct stack *)malloc(sizeof(struct stack)); s->size = 50;
 
s->top = -1;
s->arr = (char *)malloc(s->size * sizeof(char));

printf("Required Prefix : "); while (*ptr != '\0')
{
if (isalnum(*ptr)){ pre[k] = *ptr; k++;
}

else if (*ptr == '(') push(s, *ptr);

else if (*ptr == ')')
{
while ((data = pop(s)) != '('){ pre[k] = data;
k++;
}
}

else
{
while (precedence(s->arr[s->top]) >= precedence(*ptr)){ pre[k]=pop(s);
k++;
}
push(s, *ptr);
}
ptr++;
}

while (s->top != -1) pre[k]=pop(s);

printf("%s", strrev(pre));
}
