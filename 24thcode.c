#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char name[20],school[20];
    int score;
    struct node *link;
};
struct node* creat()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("hi");
    }
    else
    {
        scanf("%s%s%d",newnode->name,newnode->school,&newnode->score);
        newnode->link=NULL;
    }
    return newnode;
}
struct node* insert_end(struct node *head)
{
    struct node *newnode=creat();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node *cur=NULL;
        cur=head;
        while(cur->link!=NULL)
        {
          cur=cur->link;
        }
        cur->link=newnode;
    }
    return head;
}
void display(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
    {
        printf("ij");
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            printf("%s %s %d\n",cur->name,cur->school,cur->score);
            cur=cur->link;
        }
    }
}
int count_nodes(struct node *head)
{
    struct node *cur=NULL;
    int count=0;
    if(head==NULL)
    {
        printf("hi");
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            count++;
            cur=cur->link;
        }
    }
    return count;
}
struct node* insert_pos(struct node *head,int pos)
{
    struct node *newnode=creat();
    int count=count_nodes(head);
    struct node *cur=NULL,*next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else if(pos==1)
    {
        newnode->link=head;
        head=newnode;
    }
    else if(pos>=count)
    {
        cur=head;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
    }
    else if(pos>1&&pos<count)
    {
        cur=head;
        for(int i=1;i<pos-1;i++)
        {

            cur=cur->link;
            next=cur->link;

        }
        newnode->link=next;
        cur->link=newnode;
    }
    return head;
}
struct node* delete_pos(struct node *head)
{
    struct node *cur=NULL,*prev=NULL,*temp=NULL;
    if(head==NULL)
    {
        printf("ji");
    }
    else if(head->score==0)
    {
        temp=head;
        head=head->link;
        free(temp);
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            if(cur->score==0)
            {
                prev->link=cur->link;
                free(cur);
                break;
            }
            prev=cur;
            cur=cur->link;
        }
    }
    return head;
}
int main() {
    struct node *head=NULL;
    int n,pos,h,j;
    scanf("%d",&n);
    if(n>1)
    {
        for(int i=0;i<n;i++)
        {
            head=insert_end(head);

        }
        scanf("%d",&h);
        printf("List after insertion is:\n");
        for(int i=0;i<h;i++)
        {
            scanf("%d",&pos);
            head=insert_pos(head, pos);
        }
        display(head);
        printf("\n");
        scanf("%d",&j);
        for(int i=0;i<j;i++)
        {
            head=delete_pos(head);
        }
        printf("List after deletion is:\n");
        display(head);
    }
    else
    {
        printf("ki");

    return 0;
}
}
