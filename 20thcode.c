#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 struct node
{
    int data;
    struct node *link;

};
struct node* creat_node()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("memmory not allocted");

    }
    else
    {
        scanf("%d",&newnode->data );
        newnode->link=NULL;
    }
    return newnode;


}
struct node* insert_front (struct node *head)
{
    struct node *newnode=creat_node();
    if (head==NULL)
    {
        head=newnode;

    }
    else
    {
        newnode->link=head;
        head=newnode;
    }
    return head;
}
void display_list(struct node *head)
{
    struct node *cur;
    if(head==NULL)
    {
        printf("sll is empty\n");

    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            printf("%d ",cur->data);

            cur=cur->link;
        }
        printf("\n");
         printf("\n");


    }
}
struct node *reverse_list(struct node *head)
{
    struct node *prev,*cur,*next;
    if(head==NULL)
    {
        printf("sll is empty");

    }
    else if(head->link==NULL)
    {
        return head;
    }
    else
    {
        prev=NULL;
        cur=head;
        while(cur!=NULL)
        {
            next=cur->link;
            cur->link=prev;
            prev=cur;
            cur=next;
        }
        head=prev;
    }
    return head;
}
int main() {
    int n ;
    struct node *head=NULL;
    scanf("%d",&n);
    if(n>=1)
    {
        for(int i=0;i<n;i++)
        {
             head=insert_front(head);
        }
            printf("List is:\n");
            display_list(head);
            head=reverse_list(head);

            printf("Reversed list is:\n");
            display_list(head);


    }
    else
        printf("Invalid input");



    return 0;
}


