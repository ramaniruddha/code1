#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char  name[20],collage_name[20],academic[20];
    int w_marks,tec_marks;
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

        scanf("%s%s%s%d%d",newnode->name,newnode->collage_name,newnode->academic,&newnode->w_marks,&newnode->tec_marks);
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
int minmum(struct node *head)
{
    int min=999;
    struct node *cur=head;
    while(cur!=NULL)
    {
       if(cur->w_marks<min)
       {
           min=cur->w_marks;
       }
        cur=cur->link;
    }
    return min;

}
struct node *delete(struct node *head)
{
    int min=minmum(head);

    if(head->w_marks==min)
    {
        struct node *cur=head;
        head=head->link;
        free(cur);
    }
    else
    {
        struct node *cur=head,*prev=NULL;
        while(cur->w_marks!=min)
        {
          prev=cur;
            cur=cur->link;
        }
        prev->link=cur->link;
        free(cur);
    }
    return head;
}
struct node *deletes(struct node *head,char names[])
{
    struct node *cur=NULL,*prev=NULL;
    if(strcmp(head->name, names)==0)
    {
        cur=head;
        head=head->link;
        free(cur);
    }
    else
    {
        cur=head;
        while(strcmp(cur->name,names)!=0)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=cur->link;
        free(cur);
    }
    return head;
}
void max(struct node *head)
{
    int max=0;
    struct node *cur=head;
    while(cur!=NULL)
    {
        if(cur->tec_marks>max)
        {
            max=cur->tec_marks;
        }
        cur=cur->link;
    }
    cur=head;
    while(cur!=NULL)
    {
        if(cur->tec_marks==max)
        {
            printf("%s %s %s %d %d\n",cur->name,cur->collage_name,cur->academic,cur->w_marks,cur->tec_marks);
        }
        cur=cur->link;
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
        printf("Final list is:\n");
        while(cur!=NULL)
        {
              printf("%s %s %s %d %d\n",cur->name,cur->collage_name,cur->academic,cur->w_marks,cur->tec_marks);
             cur=cur->link;

        }
    }
}
int main() {
    struct node *head=NULL;
    int n;
    char names[20];
    scanf("%d",&n);
    if(n>=5)
    {
         for(int i=0;i<n;i++)
         {
             head=insert_end(head);
           }
        head=delete(head);
        scanf("%s",names);
        head=deletes(head,names);
        display(head);
        printf("\nSelected candidate is:\n");
       max(head);


    }
    else{
        printf("Invalid input");
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

