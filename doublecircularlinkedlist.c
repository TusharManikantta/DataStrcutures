#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
 
void display(struct node *head)
{
	struct node *temp=head;
    while (head->next != temp)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("%d\n", head->data); 
}
 
void reverse_display(struct node *head)
{
    struct node *p=head,*l;
    while(p->next!=head){
        p = p->next;
    }
    l=p;
    while (p->prev!=l)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("%d\n", p->data); 
}
 
struct node *insert_at_beginning(struct node *head, int data)
{
    struct node *ptr,*p=head;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    head->prev=ptr;
    while(p->next!=head){
        p = p->next;
    }
    p->next=ptr;
    ptr->prev=p;
    head=ptr;
    return head;
}
 
struct node *insert_in_between(struct node *head, int data, int index)
{
    struct node *ptr, *p,*p1;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    p1=p->next;
    ptr->next = p1;
    p->next = ptr;
    ptr->prev=p;
    p1->prev= ptr;
    return head;
}
 
struct node *insert_at_end(struct node *head, int data)
{
    struct node *ptr, *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next=head;
    ptr->prev =p;
    head->prev=ptr;
    return head;
}
 
struct node *delete_beginning(struct node *head)
{
    struct node *temp,*p=head;
    temp = head;
    while (p->next != head)
    {
        p = p->next;
    }
    head = temp->next;
    head->prev=p;
    p->next=head;
    temp->next = NULL;
    free(temp);
    return head;
}
 
struct node *delete_between(struct node *head, int index)
{
    struct node *temp, *p1, *p2;
    p1 = head;
    int i = 0;
    while (i != index - 1)
    {
        p1 = p1->next;
        i++;
    }
    temp = p1->next;
    p2 = temp->next;
    p1->next = p2;
    p2->prev=p1;
    temp->next = NULL;
    free(temp);
    return head;
}
 
struct node *delete_end(struct node *head)
{
    struct node *temp, *p;
    temp = head;
    p = NULL;
    if (temp->next == NULL)
    {
        free(temp);
        return NULL;
    }
    else
    {
        while (temp->next != head)
        {
            p = temp;
            temp = temp->next;
        }
        p->next = head;
        head->prev=p;
        free(temp);
        return head;
    }
}
struct node *searching(struct node *head, int key)
{
    int pos = 0;
    struct node *temp=head;
    while (head->data != key && head->next != temp)
    {
        head = head->next;
        pos++;
    }
    if (head->next == temp && head->data != key)
        printf("Entered key not found\n");
    else
        printf("%d is found at position %d of the linked list\n", key, pos);
}
 
void main()
{
    struct node *head = NULL, *new, *temp,*temp2;
    int choice = 1;
    printf("Creating linked list:\n");
    while (choice)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &new->data);
        new->next = NULL;
        new->prev = NULL;
        if (head == NULL)
        {
            head = new;
            temp = new;
        }
        else
        {
            temp2 = temp;
            temp->next = new;
            temp = new;
            temp->prev = temp2;
        }
        printf("Do you want to continue(1-YES/0-NO)?:");
        scanf("%d", &choice);
    }
    new->next=head;
    head->prev=new;
    printf("\nCreated circular doubly linked list:\n");
    display(head);
    printf("\nIn reverse direction:\n");
    reverse_display(head);
    int choice2 = 1;
    while (choice2)
    {
        int choice2, choice3;
        printf("\nMENU:\n1.INSERT\n2.DELETE\n3.SEARCH\n4.REVERSE\n5.EXIT\nEnter:");
        scanf("%d", &choice2);
        if (choice2 == 1)
        {
            printf("\nINSERTION:\n1-AT THE BEGINNING\n2-IN MIDDLE\n3-AT THE END\nEnter:");
            scanf("%d", &choice3);
            if (choice3 == 1)
            {
                // INSERTION AT THE BEGINNING
                int data1;
                printf("Enter data:");
                scanf("%d", &data1);
                head = insert_at_beginning(head, data1);
                display(head);
            }
            if (choice3 == 2)
            {
                // INSERTION IN BETWEEN
                int index, data2;
                printf("Enter data:");
                scanf("%d", &data2);
                printf("Enter the index for insertion:");
                scanf("%d", &index);
                head = insert_in_between(head, data2, index);
                display(head);
            }
            if (choice3 == 3)
            {
                // INSERTION AT THE END
                int data3;
                printf("Enter data:");
                scanf("%d", &data3);
                head = insert_at_end(head, data3);
                display(head);
            }
        }
        if (choice2 == 2)
        {
            printf("\nDELETION:\n1-1st elment\n2-between\n3-end\nEnter:");
            scanf("%d", &choice3);
            if (choice3 == 1)
            {
                // DELETE THE 1st ELEMENT
                head = delete_beginning(head);
                /*if (head == NULL)
                {
                    printf("Linked list is empty");
                }*/
                display(head);
            }
            if (choice3 == 2)
            {
                // DELETE BETWEEN ELEMENT
                int index;
                printf("Enter the index:");
                scanf("%d", &index);
                head = delete_between(head, index);
                display(head);
            }
            if (choice3 == 3)
            {
                // DELETE LAST ELEMENT
                head = delete_end(head);
                if (head == NULL)
                {
                    printf("Linked list is empty");
                }
                display(head);
            }
        }
        if (choice2 == 3)
        {
            // SEARCH
            printf("\nSEARCHING:\n");
            int key;
            printf("Enter key:");
            scanf("%d", &key);
            searching(head, key);
        }
        if (choice2 == 4)
        	reverse_display(head);
        if (choice2 == 5)
            break;
        if (choice2 < 1 || choice2 > 5)
            printf("ENTER A VALID CHOICE\n");
    }
    printf("\nFinal linked list:\n");
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    display(head);
}
