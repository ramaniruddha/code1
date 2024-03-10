#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char state[20];
    int weight,d,m,y;
    struct node *link;
};
struct node* creat()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("memor not allocated");
    }
    else
    {

        scanf("%s%d%d%d%d",newnode->state,&newnode->weight,&newnode->d,&newnode->m,&newnode->y);
        newnode->link=NULL;
    }
    return newnode;
}
struct node* insert_end(struct node *head)
{
    struct node *newnode=creat();
    struct node *cur=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else if(head->link==NULL)
    {
        head->link=newnode;
    }
    else
    {
        cur=head;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
    }
    return head;

}
struct node* insert_front(struct node *head)
{
    struct node *newnode=creat();
    if(head==NULL)
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
void kar(struct node *head,char d[])
{
    struct node *cur=NULL;
     if(head==NULL)
    {
     printf("hi");
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            if(strcmp(cur->state,d)==0)
            {
                printf("%s %d %d %d %d\n",cur->state,cur->weight,cur->d,cur->m,cur->y);
            }
            cur=cur->link;
        }
    }
}
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("the node is empty");

    }
    else
    {
        struct node *cur=head;
        while(cur!=NULL)
        {
              printf("%s %d %d %d %d\n",cur->state,cur->weight,cur->d,cur->m,cur->y);
             cur=cur->link;

        }
    }
}
int main() {
     struct node *head=NULL;
    int n,j;
    char d[20];
    scanf("%d",&n);
    if(n>0)
    {
        for(int i=0;i<n;i++)
         {
             head=insert_end(head);
           }
        scanf("%d",&j);
         for(int i=0;i<j;i++)
         {
             head=insert_front(head);
           }
        printf("Main list is:\n");
        display(head);
        printf("\n");
        scanf("%s",d);
        printf("%s list is:\n",d);
        kar(head,d);
    }
    else
    {
      printf("Invalid input\n");
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

