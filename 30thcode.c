#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *link;
};
struct node* creat()
{
 struct node *newnode=(struct node*)malloc(sizeof(struct node));
 if(newnode==NULL)
 {
     printf("memory not allocted\n");
 }
 else
 {
     scanf("%d",&newnode->num);
     newnode->link=newnode;
 }
 return newnode;
}
struct node* insert_front(struct node *head)
{
    struct node *newnode=creat();
    struct node *cur=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        cur=head;
        while(cur->link!=head)
        {
            cur=cur->link;
        }
        cur->link=newnode;
        newnode->link=head;
        head=newnode;

    }
    return head;
}
int node(struct node *head)
{
    int count=0;
    struct node *cur=NULL;
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        cur=head;
        do
        {
            count++;
            cur=cur->link;
        }
        while(cur!=head);
    }
    return count;
}
struct node* insert_pos(struct node *head,int pos)
{
    struct node *newnode=creat();
    int count=node(head);
    struct node *cur=NULL;
    if(pos==1&&head->link==head)
    {
        newnode->link=head;
        head->link=newnode;
        newnode=head;
    }
    else if(pos==1)
    {
        cur=head;
        while(cur->link!=head)
        {
            cur=cur->link;
        }
        cur->link=newnode;
        newnode->link=head;
        head=newnode;
    }
    else if(pos>=count)
    {
          cur = head;
        while(cur->link != head)
            cur = cur->link;
        cur->link = newnode;
        newnode->link = head;
    }
    else if(pos>1&&pos<count)
    {
        cur=head;
        for(int i=0;i<pos-2;i++)
        {
            cur=cur->link;
        }
         newnode->link=cur->link;
        cur->link=newnode;
    }
    else
    {
        printf("not fount");
    }
    return head;
}
struct node* delete_pos(struct node *head,int poss)
{
    int count=node(head);
    struct node *cur=NULL,*temp=NULL,*prev=NULL;
    if(head==NULL)
    {
        return head;
    }
    else if(poss==1&&head->link==head)
    {
        free(head);
        head=NULL;
    }
    else if(poss==1)
    {
        cur=head;
    while(cur->link!=head)
    {
        cur=cur->link;
    }
    cur->link=head->link;
    temp=head;
    head=head->link;
    free(temp);
    }
    else if(poss==count)
    {
        cur=head;
      while(cur->link!=head)
      {
          prev=cur;
          cur=cur->link;
      }
      prev->link=head;
      free(cur);
    }
    else if(poss>1&&poss<count)
    {
        cur=head;
        for(int i=0;i<poss-1;i++)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=cur->link;
        free(cur);

    }
    else
    {
        return head;
    }
    return head;
}
void display(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
    {
        printf("Empty.\n");
    }
    else
    {
        cur=head;
        do
        {
            printf("%d ",cur->num);
           cur=cur->link ;
        }
        while(cur!=head);
    }
}

int main() {
    struct node *head=NULL;
    int n,pos,poss;
    scanf("%d",&n);
    if(n>1)
    {
        for(int i=0;i<n;i++)
        {
            head=insert_front(head);
        }
        printf("Circular list is: ");
        display(head);
        printf("\n\n");
        scanf("%d",&pos);
        head=insert_pos(head, pos);
        printf("Circular list after insertion is: ");
        display(head);
        printf("\n\n");
        scanf("%d",&poss);
        head=delete_pos(head,poss);
        printf("Circular list after deletion is: ");
        display(head);
    }
    else
    {
        printf("Invalid input");
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
