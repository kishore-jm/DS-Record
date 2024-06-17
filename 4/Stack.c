#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
int stack[100],top;
void pushed(int n)
{
    int data;
    if(top==n-1)
    {
        printf("stack overflow....\n");
    }
    else
    {
        printf("enter element to be pushed : ");
        scanf("%d",&data);
        top=top+1;
        stack[top]=data;
    }
}
void poped()
{
    if(top==-1)
    {
        printf("stack underflow....\n");
    }
    else
    {
        int i=stack[top];
        top--;
        printf("the popped out element is : %d\n",i);
    }
}
void peeked()
{
    if(top==-1)
    {
        printf("the stack is empty....\n");
    }
    else
    {
        printf("the peek element is : %d\n",stack[top]);
    }
}
void display()
{
    if(top==-1)
    {
        printf("the stack is empty\n");
    }
    else
    {
        printf("the stack elements are : ");
        for(int i=top;i>=0;--i)
        {
            printf("%d  ",stack[i]);
        }
        printf("\n");
    }
}
int push(struct node**top)
{
    struct node*temp=*top,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("enter the element : ");
    scanf("%d",&newnode->data);
    if(temp==NULL)
    {
        newnode->next=NULL;
        temp=newnode;
        *top=newnode;
    }
    else
    {
        newnode->next=temp;
        *top=newnode;
    }
}
int pop(struct node**top)
{
    struct node*temp=*top;
    if(temp==NULL)
    {
        printf("stack underflow...\n");
    }
    else
    {
        printf("the popped out element is : %d\n",temp->data);
        temp=temp->next;
        *top=temp;
    }
}
int peek(struct node**top)
{
    struct node*temp=*top;
    if(temp==NULL)
    {
        printf("the stack is empty....\n");
    }
    else
    {
        printf("the peek element : %d\n",temp->data);
    }
}
int disp(struct node*top)
{
    struct node*temp=top;
    if(temp==NULL)
    {
        printf("the stack is empty.....");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
void array()
{
    top=-1;
    int n;
    printf("enter the number of elements in the stack : ");
    scanf("%d",&n);
    int k=1;
    while(k!=0)
    {
        int ch;
        printf("enter your choice : 1)push\t2)pop\t3)peek\t4)display\t5)exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                pushed(n);
                break;
            }
            case 2:
            {
                poped();
                break;
            }
            case 3:
            {
                peeked();
                break;
            }
            case 4:
            {
                display();
                break;
            }
            case 5:
            {
                printf("end of the array stack...\n");
                k=0;
                break;
            }
            default:
            {
                printf("wrong input try again....\n");
                break;
            }
        }
    }
}
void linked()
{
    struct node*top=NULL;
    int j=1;
    while(j!=0)
    {
        int ch;
        printf("enter your choice : 1)push\t2)pop\t3)peek\t4)display\t5)exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                push(&top);
                break;
            }
            case 2:
            {
                pop(&top);
                break;
            }
            case 3:
            {
                peek(&top);
                break;
            }
            case 4:
            {
                disp(top);
                break;
            }
            case 5:
            {
                printf("end of the linked list stack...\n");
                j=0;
                break;
            }
            default:
            {
                printf("wrong input try again....\n");
                break;
            }
        }
    }
}
int main()
{
    int i=1;
    while(i!=0)
    {
        int c;
        printf("enter choice : 1)array\t2)linked list\t3)exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                array();
                break;
            }
            case 2:
            {
                linked();
                break;
            }
            case 3:
            {
                printf("end of program....\n");
                i=0;
                break;
            }
            default:
            {
                printf("wrong input try again....\n");
                break;
            }
        }
    }
    return 0;
}
output:
enter choice : 1)array    2)linked list    3)exit
1
enter the number of elements in the stack : 5
enter your choice : 1)push    2)pop    3)peek    4)display    5)exit
1
enter element to be pushed : 10
enter your choice : 1)push    2)pop    3)peek    4)display    5)exit
1
enter element to be pushed : 20
enter your choice : 1)push    2)pop    3)peek    4)display    5)exit
4
the stack elements are : 20  10  
enter your choice : 1)push    2)pop    3)peek    4)display    5)exit
2
the popped out element is : 20
enter your choice : 1)push    2)pop    3)peek    4)display    5)exit
3
the peek element is : 10
enter your choice : 1)push    2)pop    3)peek    4)display    5)exit
4
the stack elements are : 10  
enter your choice : 1)push    2)pop    3)peek    4)display    5)exit
5
end of the array stack...
enter choice : 1)array    2)linked list    3)exit
2
enter your choice : 1)push    2)pop    3)peek    4)display    5)exit
1
enter the element : 15
enter your choice : 1)push    2)pop    3)peek    4)display    5)exit
1
enter the element : 25
enter your choice : 1)push    2)pop    3)peek    4)display    5)exit
4
the stack elements are : 25  15  
enter your choice : 1)push    2)pop    3)peek    4)display    5)exit
2
the popped out element is : 25
enter your choice : 1)push    2)pop    3)peek    4)display    5)exit
3
the peek element : 15
enter your choice : 1)push    2)pop    3)peek    4)display    5)exit
4
the stack elements are : 15  
enter your choice : 1)push    2)pop    3)peek    4)display    5)exit
5
end of the linked list stack...
enter choice : 1)array    2)linked list    3)exit
3
end of program....
