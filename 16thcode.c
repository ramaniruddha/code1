#include<stdio.h>
#include<stdlib.h>
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
     printf("memory not allocted");
 }
 else
 {
     scanf("%d",newnode->data);
     newnode->link=NULL;
 }
 return newnode;
}
struct node* insert_front(struct node *head)
{
    struct node *newnode=creat_node();
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
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("no node");
    }
    else
    {
        struct node *cur=head;
        while(cur!=NULL)
        {
            printf("%d",cur->data);
        }
    }
}
int main()
{
    struct node *head=NULL;
    int n,i;
    printf("eneter the valu n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        insert_front(head);

    }
     display(head);

}
