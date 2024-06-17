#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef;
    int pows;
    struct node *next;
};
int insert(struct node**head,int i,int j)
{
    struct node*newnode,*temp=*head;
    newnode=(struct node*)malloc(sizeof(struct node*));
    newnode->coef=i;
    newnode->pows=j;
    newnode->next=NULL;
    if(temp==NULL || j>temp->pows)
    {
        newnode->next=temp;
        *head=newnode;
    }
    else
    {
        while(temp->next!=NULL && temp->next->pows>=j)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
int print(struct node*head)
{
    struct node *temp=head;
    if(temp==NULL)
    {
        printf("\n no polynomial..");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%dX^%d",temp->coef,temp->pows);
            temp=temp->next;
            if(temp!=NULL && temp->coef>=0)
            {
                printf(" + ");
            }
            else if(temp!=NULL && temp->coef<0)
            {
                printf(" - ");
                int d=-(temp->coef);
                temp->coef=d;
            }
            else
            {
                printf("");
            }
        }
    }
}
int add(struct node*head1,struct node*head2)
{
    struct node*ptr1=*head1,*ptr2=*head2,*head3=NULL;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->pows==ptr2->pows)
        {
            insert(&head3,ptr1->coef+ptr2->coef,ptr1->pows);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->pows > ptr2->pows)
        {
            insert(&head3,ptr1->coef,ptr1->pows);
            ptr1=ptr1->next;
        }
        else if(ptr1->pows < ptr2->pows)
        {
            insert(&head3,ptr2->coef,ptr2->pows);
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=NULL)
    {
        insert(&head3,ptr1->coef,ptr1->pows);
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL)
    {
        insert(&head3,ptr2->coef,ptr2->pows);
        ptr2=ptr2->next;
    }
    printf("\nthe added polynomial is : \n");
    print(head3);
}
int subtract(struct node*head1,struct node*head2)
{
    struct node*ptr1=*head1,*ptr2=*head2,*head3=NULL;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->pows==ptr2->pows)
        {
            insert(&head3,(ptr1->coef)-(ptr2->coef),ptr1->pows);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->pows > ptr2->pows)
        {
            insert(&head3,(ptr1->coef),ptr1->pows);
            ptr1=ptr1->next;
        }
        else if(ptr1->pows < ptr2->pows)
        {
            insert(&head3,-(ptr2->coef),ptr2->pows);
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=NULL)
    {
        insert(&head3,ptr1->coef,ptr1->pows);
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL)
    {
        insert(&head3,-(ptr2->coef),ptr2->pows);
        ptr2=ptr2->next;
    }
    printf("\nthe subtracted polynomial is : \n");
    print(head3);
}
int multiply(struct node*head1,struct node*head2)
{
    struct node*ptr1=*head1,*ptr2=*head2,*head3=NULL;
    while(ptr1!=NULL)
    {
        ptr2=*head2;
        while(ptr2!=NULL)
        {
            int res1,res2;
            res1=ptr1->coef*ptr2->coef;
            res2=ptr1->pows+ptr2->pows;
            insert(&head3,res1,res2);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    printf("\nthe multiplied polynomial is : \n");
    print(head3);
}
int main()
{
    struct node *head1=NULL,*head2=NULL;
    int n1,n2;
    printf("POLYNOMIAL 1 : ");
    printf("\nenter number of elements in poly1 : ");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        int x,y;
        printf("enter the coef of %d element : ",i+1);
        scanf("%d",&x);
        printf("enter the power of %d element : ",i+1);
        scanf("%d",&y);
        insert(&head1,x,y);
    }
    printf("\nPOLYNOMIAL 2 : ");
    printf("\nenter number of elements in poly2 : ");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
    {
        int x,y;
        printf("enter the coef of %d element : ",i+1);
        scanf("%d",&x);
        printf("enter the power of %d element : ",i+1);
        scanf("%d",&y);
        insert(&head2,x,y);
    }
    int i=1;
    while(i!=0)
    {
        int ch;
        printf("\nenter your choice : 1)add\t2)subtract\t3)multiply\t4)exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                add(&head1,&head2);
                break;
            }
            case 2:
            {
                subtract(&head1,&head2);
                break;
            }
            case 3:
            {
                multiply(&head1,&head2);
                break;
            }
            case 4:
            {
                printf("\nend of the program...");
                i=0;
                break;
            }
            default:
            {
                printf("\n wrong input try again..\n");
                break;
            }
        }
    }
    return 0;
}
output:
POLYNOMIAL 1 :
enter number of elements in poly1 : 3
enter the coef of 1 element : 2
enter the power of 1 element : 3
enter the coef of 2 element : -1
enter the power of 2 element : 2
enter the coef of 3 element : 5
enter the power of 3 element : 0

POLYNOMIAL 2 :
enter number of elements in poly2 : 4
enter the coef of 1 element : 4
enter the power of 1 element : 3
enter the coef of 2 element : 2
enter the power of 2 element : 2
enter the coef of 3 element : -3
enter the power of 3 element : 1
enter the coef of 4 element : 1
enter the power of 4 element : 0

enter your choice : 1)add  2)subtract  3)multiply  4)exit
1

the added polynomial is :
4X^3 + 1X^2 - 3X^1 + 6X^0

enter your choice : 1)add  2)subtract  3)multiply  4)exit
2

the subtracted polynomial is :
-2X^3 - 3X^1 + 4X^0

enter your choice : 1)add  2)subtract  3)multiply  4)exit
3

the multiplied polynomial is :
8X^6 + 4X^5 - 12X^4 + 5X^3 - 2X^2 - 15X^1 + 5X^0

enter your choice : 1)add  2)subtract  3)multiply  4)exit
4

end of the program...
