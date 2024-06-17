#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *right,*left;
};
struct node*insert(struct node**root)
{
    struct node*newnode,*temp=*root,*kemp=*root;
    int x,y=1;
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("enter element to be inserted (-1 for no node) : ");
    scanf("%d",&x);
    if(x!=-1)
    {
        newnode->data=x;
        newnode->left=NULL;
        newnode->right=NULL;
        if(*root==NULL)
        {
            *root=newnode;
        }
        else
        {
            while(temp!=NULL)
            {
                if(x<temp->data)
                {
                    y=1;kemp=temp;
                    temp=temp->left;
                }
                else
                {
                    y=0;
                    kemp=temp;
                    temp=temp->right;
                }
            }
            if(y==1)
            {
                kemp->left=newnode;
            }
            else
            {
                kemp->right=newnode;
            }
        }
        return *root;
    }
    else
    {
        return NULL;
    }
}
void display(struct node*roote)
{
    struct node*temp=roote;
    if(roote==NULL)
    {
        return;
    }
    else
    {
        printf("%d->",temp->data);
        display(temp->left);
        display(temp->right);
    }
}
struct node*minvalue(struct node*root)
{
   struct node*current=root;
   while(current && current->left !=NULL)
   {
      current=current->left;
   }
   return current;
}
struct node*delete (struct node*root,int data)
{
   if(root==NULL)
   {
     return root;
   }
   if(data<root->data)
   {
     root->left=delete (root->left,data);
   }
   else if(data>root->data)
   {
     root->right=delete (root->right ,data);
   }
   else
   {
     if(root->left==NULL)
     {
       struct node*temp=root->right;
       free(root);
       return temp;
     }
     else if(root->right==NULL)
     {
       struct node*temp=root->left;
       free(root);
       return temp;
     }
     struct node*temp=minvalue (root->right);
     root->data=temp->data;
     root->right=delete(root->right, temp ->data);
   }
   return root;
}
void search(struct node**root)
{
    struct node*temp=*root;
    printf("enter seacrh element : ");
    int sear;
    scanf("%d",&sear);
    if(temp==NULL)
    {
        printf("element not found\n");
        return;
    }
    else
    {
        int i=1;
        while(temp!=NULL)
        {
            if(i==0)
            {
                break;
            }
            if(temp->data==sear)
            {
                printf("element found\n");
                i=0;
            }
            else if(sear<temp->data)
            {
                temp=temp->left;
            }
            else if(sear>temp->data)
            {
                temp=temp->right;
            }
            if(temp==NULL)
            {
                printf("element not found\n");
            }
        }
    }
}
void main()
{
    struct  node*root=NULL,*roote;
    int ch,i=1;
    while(i!=0)
    {
        root=roote;
        printf("enter ur choice : 1)insert 2)delete 3)search 4)display 5)exit : \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                roote=insert(&root);
                break;
            }
            case 2:
            {
                int dat;
                printf("enter the data to be deleted:");
                scanf("%d",&dat);
                roote=delete(root,dat);
                break;
            }
            case 3:
            {
                search(&root);
                break;
            }
            case 4:
            {   
                display(roote);
                printf("NULL\n");
                break;
            }
            case 5:
            {
                printf("end of the program....\n");
                i=0;
                break;
            }
            default:
            {
                printf("wrong input try again..\n");
                break;
            }
        }
    }
}
output:
enter ur choice : 1)insert 2)delete 3)search 4)display 5)exit :
1
enter element to be inserted (-1 for no node) : 50
enter ur choice : 1)insert 2)delete 3)search 4)display 5)exit :
1
enter element to be inserted (-1 for no node) : 30
enter ur choice : 1)insert 2)delete 3)search 4)display 5)exit :
1
enter element to be inserted (-1 for no node) : 20
enter ur choice : 1)insert 2)delete 3)search 4)display 5)exit :
1
enter element to be inserted (-1 for no node) : 40
enter ur choice : 1)insert 2)delete 3)search 4)display 5)exit :
1
enter element to be inserted (-1 for no node) : 70
enter ur choice : 1)insert 2)delete 3)search 4)display 5)exit :
1
enter element to be inserted (-1 for no node) : 60
enter ur choice : 1)insert 2)delete 3)search 4)display 5)exit :
1
enter element to be inserted (-1 for no node) : 80
enter ur choice : 1)insert 2)delete 3)search 4)display 5)exit :
4
50->30->20->40->70->60->80->NULL
enter ur choice : 1)insert 2)delete 3)search 4)display 5)exit :
2
enter the data to be deleted:60
enter ur choice : 1)insert 2)delete 3)search 4)display 5)exit :
4
50->30->20->40->70->80->NULL
enter ur choice : 1)insert 2)delete 3)search 4)display 5)exit :
3
enter seacrh element : 70
element found
enter ur choice : 1)insert 2)delete 3)search 4)display 5)exit :
3
enter seacrh element : 90
element not found
enter ur choice : 1)insert 2)delete 3)search 4)display 5)exit :
5
end of the program....
