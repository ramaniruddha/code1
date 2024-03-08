#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct d
{
     char name[20], SRN[20], project_Name[20];
    int Semester;
};
void read_struct(struct d *sptr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("enter the name ,srn,project_name,semester of %d",i+1);
        scanf("%s%s%s%d",sptr[i].name,sptr[i].SRN,sptr[i].project_Name,&sptr[i].Semester);
    }
}
void display_struct(struct d *sptr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%s %s %s %d\n",sptr[i].name,sptr[i].SRN,sptr[i].project_Name,sptr[i].Semester);
    }
}
void display_sp(struct d *sptr,int n)
{
    char s[]="01fe22bec298";
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(s,sptr[i].SRN)==0)
        {
            if(sptr[i].Semester==4)
             printf("selected person is %s %s %s %d\n",sptr[i].name,sptr[i].SRN,sptr[i].project_Name,sptr[i].Semester);
        }
    }
}
int main()
{
    struct d e1[100];
    struct d *sptr=e1;
    int n;
    printf("enter the value of n\n");
    scanf("%d",&n);
    read_struct(sptr,n);
    display_struct(sptr,n);
    display_sp(sptr,n);
    return 0;
}
