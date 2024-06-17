#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
int isempty(struct node*list)
{
    return list==NULL;
}
int islast(struct node*pos)
{
    return pos->next==NULL;
}
struct node*find(struct node*list,int x)
{
    struct node*temp=list;
    while(temp!=NULL&&temp->data!=x)
    {
        temp=temp->next;
    }
    return temp;
}
struct node*findprevious(struct node*list,int x)
{
    struct node*temp=list;
    if(temp!=NULL && temp->data==x)
    {
        return NULL;
    }
    while(temp->next!=NULL && temp->next->data!=x)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        return NULL;
    }
    return temp;
}
struct node*findnext(struct node*list,int x)
{
    struct node*temp=find(list,x);
    if(temp!=NULL)
    {
        return temp->next;
    }
    return NULL;
}
void insertbeg(struct node**list,int x)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node*));
    newnode->next=*list;
    newnode->data=x;
    *list=newnode;
}
void  insertafter(struct node*list,int p,int x)
{
    struct node*temp=find(list,p);
    if(temp!=NULL)
    {
        struct node*newnode=(struct node*)malloc(sizeof(struct node*));
        newnode->data=x;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    else
    {
        printf("position element not found.\n");
    }
}
void insertend(struct node**list,int x)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node*));
    newnode->next=NULL;
    newnode->data=x;
    if(isempty(*list))
    {
       *list=newnode; 
    }
    else
    {
        struct node*temp=*list;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void delbeg(struct node**list)
{
    if(!isempty(*list))
    {
        struct node*temp=*list;
        *list=(*list)->next;
        printf("The Deleted Element : %d\n",temp->data);
        free(temp);
    }
    else
    {
        printf("The List Is Empty.\n");
    }
}
void delaft(struct node*list,int p)
{
    struct node*temp,*pos=find(list,p);
    if(pos!=NULL && pos->next!=NULL)
    {
        temp=pos->next;
        pos->next=temp->next;
        printf("Deleted Element : %d\n",temp->data);
        free(temp);
    }
    else
    {
        printf("position element or next element not found.\n");
    }
}
void delend(struct node**list)
{
    if(!isempty(*list))
    {
        struct node*k=NULL,*temp=*list;
        while(temp->next!=NULL)
        {
            k=temp;
            temp=temp->next;
        }
        if(k!=NULL)
        {
            k->next=NULL;
        }
        else
        {
            *list=NULL;
        }
        printf("Deleted Element : %d\n",temp->data);
        free(temp);
    }
    else
    {
        printf("The List Is Empty.\n");
    }
}
void dellist(struct node**list)
{
    struct node*temp=*list,*cur;
    while(temp!=NULL)
    {
        cur=temp->next;
        printf("Deleted Element: %d\n",temp->data);
        free(temp);
        temp=cur;
    }
    *list=NULL;
}
void display(struct node*list)
{
    struct node*temp=list;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main()
{
    struct node*list=NULL;
    int p,ch,x,i=1;
    while(i!=0)
    {
        printf("1)inbeg\t2)inmid\t3)inend\t4)fe\t5)fne\t6)fpe\t7)last?\t8)empty?\t9)delbeg\t10)delmid\t11)delend\t12)dellist\t13)disp\t14)exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter Element:");
                scanf("%d",&x);
                insertbeg(&list,x);
                break;
            }
            case 2:
            {
                printf("Enter position Element:");
                scanf("%d",&p);
                printf("Enter Element:");
                scanf("%d",&x);
                insertafter(list,p,x);
                break;
            }
            case 3:
            {
                printf("Enter Element:");
                scanf("%d",&x);
                insertend(&list,x);
                break;
            }
            case 4:
            {
                printf("Enter the element to find: ");
                scanf("%d", &x);
                if (find(list,x) != NULL) {
                    printf("Element found.\n");
                } else {
                    printf("Element not found.\n");
                }
                break;
            }
            case 5:
            {
                printf("Enter the element to find next: ");
                scanf("%d", &x);
                struct node *next = findnext(list,x);
                if (next != NULL) {
                    printf("Next element: %d\n", next->data);
                } else {
                    printf("Next element not found.\n");
                }
                break;
            }
            case 6:
            {
                printf("Enter the element to find previous: ");
                scanf("%d", &x);
                struct node *prev = findprevious(list,x);
                if (prev != NULL) {
                    printf("Previous element: %d\n", prev->data);
                } else {
                    printf("Previous element not found.\n");
                }
                break;
            }
            case 7:
            {
                printf("Enter the element to check if last: ");
                scanf("%d", &x);
                struct node *pos = find(list,x);
                if (pos != NULL && islast(pos)) {
                    printf("It is the last element.\n");
                } else {
                    printf("It is not the last element.\n");
                }
                break;
            }
            case 8:
            {
                if (isempty(list)) {
                    printf("List is empty.\n");
                } else {
                    printf("List is not empty.\n");
                }
                break;
            }
            case 9:
            {
                delbeg(&list);
                break;
            }
            case 10:
            {
                printf("Enter the position element: ");
                scanf("%d", &p);
                delaft(list, p);
                break;
            }
            case 11:
            {
                delend(&list);
                break;
            }
            case 12:
            {
                dellist(&list);
                break;
            }
            case 13:
            {
                display(list);
                break;
            }
            case 14:
            {
                i=0;
                printf("Exiting...\n");
                break;
            }
        }
    }
}


output:
1)inbeg	2)inmid	3)inend	4)fe	5)fne	6)fpe	7)last?	8)empty?	9)delbeg	10)delmid	11)delend	12)dellist	13)disp	14)exit
1
Enter Element:1
1)inbeg	2)inmid	3)inend	4)fe	5)fne	6)fpe	7)last?	8)empty?	9)delbeg	10)delmid	11)delend	12)dellist	13)disp	14)exit
3
Enter Element:3
1)inbeg	2)inmid	3)inend	4)fe	5)fne	6)fpe	7)last?	8)empty?	9)delbeg	10)delmid	11)delend	12)dellist	13)disp	14)exit
2
Enter position Element:1
Enter Element:2
1)inbeg	2)inmid	3)inend	4)fe	5)fne	6)fpe	7)last?	8)empty?	9)delbeg	10)delmid	11)delend	12)dellist	13)disp	14)exit
13
1->2->3->NULL
1)inbeg	2)inmid	3)inend	4)fe	5)fne	6)fpe	7)last?	8)empty?	9)delbeg	10)delmid	11)delend	12)dellist	13)disp	14)exit
4
Enter the element to find: 4
Element not found.
1)inbeg	2)inmid	3)inend	4)fe	5)fne	6)fpe	7)last?	8)empty?	9)delbeg	10)delmid	11)delend	12)dellist	13)disp	14)exit
5
Enter the element to find next: 2
Next element: 3
1)inbeg	2)inmid	3)inend	4)fe	5)fne	6)fpe	7)last?	8)empty?	9)delbeg	10)delmid	11)delend	12)dellist	13)disp	14)exit
6
Enter the element to find previous: 1
Previous element not found.
1)inbeg	2)inmid	3)inend	4)fe	5)fne	6)fpe	7)last?	8)empty?	9)delbeg	10)delmid	11)delend	12)dellist	13)disp	14)exit
7
Enter the element to check if last: 1
It is not the last element.
1)inbeg	2)inmid	3)inend	4)fe	5)fne	6)fpe	7)last?	8)empty?	9)delbeg	10)delmid	11)delend	12)dellist	13)disp	14)exit
8
List is not empty.
1)inbeg	2)inmid	3)inend	4)fe	5)fne	6)fpe	7)last?	8)empty?	9)delbeg	10)delmid	11)delend	12)dellist	13)disp	14)exit
9
The Deleted Element : 1
1)inbeg	2)inmid	3)inend	4)fe	5)fne	6)fpe	7)last?	8)empty?	9)delbeg	10)delmid	11)delend	12)dellist	13)disp	14)exit
10
Enter the position element: 2
Deleted Element : 3
1)inbeg	2)inmid	3)inend	4)fe	5)fne	6)fpe	7)last?	8)empty?	9)delbeg	10)delmid	11)delend	12)dellist	13)disp	14)exit
11
Deleted Element : 2
1)inbeg	2)inmid	3)inend	4)fe	5)fne	6)fpe	7)last?	8)empty?	9)delbeg	10)delmid	11)delend	12)dellist	13)disp	14)exit
13
NULL
1)inbeg	2)inmid	3)inend	4)fe	5)fne	6)fpe	7)last?	8)empty?	9)delbeg	10)delmid	11)delend	12)dellist	13)disp	14)exit
12
1)inbeg	2)inmid	3)inend	4)fe	5)fne	6)fpe	7)last?	8)empty?	9)delbeg	10)delmid	11)delend	12)dellist	13)disp	14)exit
14
Exiting...


=== Code Execution Successful ===
