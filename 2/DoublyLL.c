#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
};
int inbeg(struct node**head)
{
    struct node *temp=*head,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node*));
    newnode->next=temp;
    newnode->prev=NULL;
    printf("\nelement to be inserted at first : ");
    scanf("%d",&newnode->data);
    *head=newnode;
}
int inend(struct node**head)
{
    struct node*temp=*head,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("\nelement to be enetered at last : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    newnode->prev=temp;
    temp->next=newnode;
}
int inpos(struct node**head)
{
    struct node*temp=*head,*newnode,*kemp;
    newnode=(struct node*)malloc(sizeof(struct node*));
    int pos,y=0;
    printf("\nenter position : ");
    scanf("%d",&pos);
    printf("\nelement to be inserted at pos : ");
    scanf("%d",&newnode->data);
    while(y<pos)
    {
        kemp=temp;
        temp=temp->next;
        y++;
    }
    newnode->prev=kemp;
    kemp->next=newnode;
    newnode->next=temp;
}
int delbeg(struct node**head)
{
    struct node*temp=*head,*kemp;
    if(temp->next==NULL)
    {
        *head=NULL;
        free(temp);
    }
    else
    {
        *head=temp->next;
        kemp=temp->next;
        kemp->prev=NULL;
        free(temp);
    }
}
int delend(struct node**head)
{
    struct node*temp=*head,*kemp;
    if(temp->next==NULL)
    {
        *head=NULL;
        free(temp);
    }
    else
    {
        while(temp->next!=NULL)
        {
            kemp=temp;
            temp=temp->next;
        }
        kemp->next=NULL;
        free(temp);
    }
}
int delpos(struct node**head)
{
    struct node*temp=*head,*kemp,*lemp;
    if(temp->next==NULL)
    {
        printf("\nposition is zero.\n");
        *head=NULL;
        free(temp);
    }
    else
    {
        int pos,y=0;
        printf("\nenter the position to be deleted : ");
        scanf("%d",&pos);
        if(pos==0)
        {
            *head=temp->next;
            kemp=temp->next;
            kemp->prev=NULL;
            free(temp);
        }
        else
        {
            while(y<pos)
            {
                kemp=temp;
                temp=temp->next;
                y++;
            }
            if(temp->next!=NULL)
            {
                kemp->next=temp->next;
                lemp=temp->next;
                lemp->prev=kemp;
                free(temp);
            }
            else
            {
                kemp->next=NULL;
                free(temp);
            }
        }
    }
}
int search(struct node**head)
{
    struct node*temp=*head;
    int k,y=-1,i=-1;
    printf("\nelement to be searched : ");
    scanf("%d",&k);
    while(temp!=NULL)
    {
        y++;
        if(k==temp->data)
        {
            printf("element found at position : %d\n",y);
            i++;
        }
        temp=temp->next;
    }
    if(i==-1)
    {
        printf("\nelement not found in the list \n");
    }
}
int disp(struct node*head)
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int i=1;
    struct node*head=NULL;
    while(i!=0)
    {
        int ch,ch1,ch2;
        printf("1)insert\t2)delete\t3)search\t4)exit.\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("1)beg\t2)pos\t3)end\n");
                scanf("%d",&ch1);
                switch(ch1)
                {
                    case 1:
                    {
                        inbeg(&head);
                        break;
                    }
                    case 2:
                    {
                        inpos(&head);
                        break;
                    }
                    case 3:
                    {
                        inend(&head);
                        break;
                    }
                    default:
                    {
                        printf("\nwrong input....");
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                printf("1)beg\t2)pos\t3)end.\n");
                scanf("%d",&ch2);
                switch(ch2)
                {
                    case 1:
                    {
                        delbeg(&head);
                        break;
                    }
                    case 2:
                    {
                        delpos(&head);
                        break;
                    }
                    case 3:
                    {
                        delend(&head);
                        break;
                    }
                    default:
                    {
                        printf("\nwrong input.....");
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                search(&head);
                break;
            }
            case 4:
            {
                printf("\nend of the program");
                i=0;
                break;
            }
            default:
            {
                printf("\nwrong input try again..");
                break;
            }
        }
        disp(head);
    }
    return 0;
}
output :
1)insert	2)delete	3)search	4)exit.
1
1)beg	2)pos	3)end
1

element to be inserted at first : 10
10->NULL
1)insert	2)delete	3)search	4)exit.
1
1)beg	2)pos	3)end
3

element to be enetered at last : 20
10->20->NULL
1)insert	2)delete	3)search	4)exit.
1
1)beg	2)pos	3)end
2

enter position : 1

element to be inserted at pos : 15
10->15->20->NULL
1)insert	2)delete	3)search	4)exit.
1
1)beg	2)pos	3)end
1

element to be inserted at first : 5
5->10->15->20->NULL
1)insert	2)delete	3)search	4)exit.
1
1)beg	2)pos	3)end
3

element to be enetered at last : 25
5->10->15->20->25->NULL
1)insert	2)delete	3)search	4)exit.
2
1)beg	2)pos	3)end.
1
10->15->20->25->NULL
1)insert	2)delete	3)search	4)exit.
2
1)beg	2)pos	3)end.
3
10->15->20->NULL
1)insert	2)delete	3)search	4)exit.
2
1)beg	2)pos	3)end.
2

enter the position to be deleted : 1
10->20->NULL
1)insert	2)delete	3)search	4)exit.
3

element to be searched : 10
element found at position : 0
10->20->NULL
1)insert	2)delete	3)search	4)exit.
3

element to be searched : 20
element found at position : 1
10->20->NULL
1)insert	2)delete	3)search	4)exit.
3

element to be searched : 30

element not found in the list 
10->20->NULL
1)insert	2)delete	3)search	4)exit.
4

end of the program10->20->NULL


=== Code Execution Successful ===
