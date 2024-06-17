#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
int stack[100],head,top,front;
void enq(int n)
{
    int data;
    if(top==n-1)
    {
        printf("queue overflow....\n");
    }
    else
    {
        printf("enter element to be added : ");
        scanf("%d",&data);
        top=top+1;
        stack[top]=data;
    }
}
void deq()
{
    if(front>top)
    {
        printf("queue underflow....\n");
    }
    else
    {
        int i=stack[front];
        front=front+1;
        printf("the deleted element is : %d\n",i);
    }
}
void display()
{
    if(front>top)
    {
        printf("the queue is empty\n");
    }
    else
    {
        printf("the queue elements are : ");
        for(int i=front;i<=top;i++)
        {
            printf("%d  ",stack[i]);
        }
        printf("\n");
    }
}
int enqu(struct node**head)
{
    struct node*temp=*head,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("enter the element : ");
    scanf("%d",&newnode->data);
    if(temp==NULL)
    {
        newnode->next=NULL;
        *head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
}
int dequ(struct node**head)
{
    struct node*temp=*head;
    if(temp==NULL)
    {
        printf("queue underflow...\n");
    }
    else
    {
        printf("the deleted element is : %d\n",temp->data);
        *head=temp->next;
        
    }
}
int disp(struct node*head)
{
    struct node*temp=head;
    if(temp==NULL)
    {
        printf("the queue is empty.....\n");
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
    top=-1,front=0;
    int n;
    printf("enter the number of elements in the queue : ");
    scanf("%d",&n);
    int k=1;
    while(k!=0)
    {
        int ch;
        printf("enter your choice : 1)enqueue\t2)dequeue\t3)display\t4)exit\n");
        scanf("%d",&ch);    
        switch(ch)
        {
            case 1:
            {
                enq(n);
                break;
            }
            case 2:
            {
                deq();
                n++;
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("end of the array Queue...\n");
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
    struct node*head=NULL;
    int j=1;
    while(j!=0)
    {
        int ch;
        printf("enter your choice : 1)enqueue\t2)dequeue\t3)display\t4)exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                enqu(&head);
                break;
            }
            case 2:
            {
                dequ(&head);
                break;
            }
            case 3:
            {
                disp(head);
                break;
            }
            case 4:
            {
                printf("end of the linked list queue...\n");
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
    printf("Queue:\n");
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
Queue:
enter choice : 1)array	2)linked list	3)exit
1
enter the number of elements in the queue : 5
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
1
enter element to be added : 1
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
1
enter element to be added : 2
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
1
enter element to be added : 3
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
3
the queue elements are : 1  2  3  
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
2
the deleted element is : 1
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
1
enter element to be added : 4
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
1
enter element to be added : 5
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
3
the queue elements are : 2  3  4  5  
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
4
end of the array Queue...
enter choice : 1)array	2)linked list	3)exit
2
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
1
enter the element : 1
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
1
enter the element : 2
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
1
enter the element : 3
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
3
1->2->3->NULL
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
2
the deleted element is : 1
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
1
enter the element : 4
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
1
enter the element : 5
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
3
2->3->4->5->NULL
enter your choice : 1)enqueue	2)dequeue	3)display	4)exit
4
end of the linked list queue...
enter choice : 1)array	2)linked list	3)exit
3
end of program....
