#include<stdio.h>
#include<stdlib.h>

struct node
{
    char name[10];
    char usn[10];
    char section[10];
     struct node *link;

};
typedef struct node *ptr;
ptr first=NULL;

ptr create()
{
    ptr new;
    new=(ptr*)malloc(sizeof(struct node));
    printf("enter name\n");
    scanf("%s",&new->name);
    printf("enter usn\n");
    scanf("%s",&new->usn);
    printf("enter section\n");
    scanf("%s",&new->section);
    new->link=NULL;
    return new;
}
ptr insert_rear()
{
    ptr new=create();
    ptr temp=first;
    if(first==NULL)
    {
        first=new;

    }
    else{
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=new;

        new->link=NULL;
    }

}
ptr insert_front()
{
    ptr new=create();

    if(first==NULL)
    {
       first=new;
    }
    else
        {
        new->link=first;
        first=new;
    }
}


ptr insert()
{
    int ch;
    printf("enter your choice\n");
    printf("1.insert at front end\n2.insert at rear end\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:insert_front();
        break;
        case 2:insert_rear();
    break;
    default:printf("invalid choice\n");
    }
}





ptr delete_front()
{
    if(first==NULL)
        printf("list is empty");
    else{
        first=first->link;

    }
}
ptr delete_rear()
{
    ptr temp=first;
    ptr prev;
if(first==NULL)
        printf("list is empty");
        else{
             while(temp->link!=NULL)
        {
            temp=(temp->link);
        }

        temp=NULL;
        prev->link=NULL;
        if(prev==NULL)
            first=NULL;

    }

}

ptr delete()
{
    int ch;
    printf("enter your choice\n");
    printf("1.delete from front end\n2.delete from rear end\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:delete_front();
        break;
        case 2:delete_rear();
    break;
    default:printf("invalid choice\n");
    }
}
ptr display()
{

    ptr temp=first;

    if(first==NULL)
        printf("list is empty\n");
        else
            {

            for(temp=first;temp!=NULL;temp=temp->link)
                {
            printf("%s\n",&temp->name);
              printf("%s\n",&temp->usn);
               printf("%s\n",&temp->section);


            }
        }
}

void main()
{
int ch;
while(1)
{
    printf("enter your choice\n");
    printf("1.insert\n2.delete\n3.display\n4.exit\n");
scanf("%d",&ch);
    switch(ch)
    {
        case 1:insert();
        break;
        case 2:delete();
        break;
        case 3:display();
        break;
        case 4:exit(0);
        break;
        default:printf("invalid choice\n");
        break;
    }

  }
}

