#include <stdio.h>
#include <stdlib.h>

struct Tree {
    int ele;
    struct Tree* left;
    struct Tree* right;
};

// Function prototypes
struct Tree* create(struct Tree* root, int x);
void inorder(struct Tree* root);
void preorder(struct Tree* root);
void postorder(struct Tree* root);

int main() {
    struct Tree* root = NULL;
    int n=1, x,ch;
    while(n!=0)
    {
        printf("1)insert\t 2)print\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("element:");
                scanf("%d", &x);
                root = create(root, x);
                break;
            }
            case 2:
            {
                n=0;
                break;
            }
            default:
            {
                break;
            }
        }
    }
    printf("INORDER TRAVERSAL IS: ");
    inorder(root);
    printf("\nPOSTORDER TRAVERSAL IS: ");
    postorder(root);
    printf("\nPREORDER TRAVERSAL IS: ");
    preorder(root);

    return 0;
}

// Function to create a new node in BST
struct Tree* create(struct Tree* root, int x) {
    if (root == NULL) {
        struct Tree* newnode = malloc(sizeof(struct Tree));
        newnode->ele = x;
        newnode->left = NULL;
        newnode->right = NULL;
        root = newnode;
    } else if (x < root->ele) {
        root->left = create(root->left, x);
    } else if (x > root->ele) {
        root->right = create(root->right, x);
    }
    return root;
}

// Function for inorder traversal
void inorder(struct Tree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->ele);
        inorder(root->right);
    }
}

// Function for preorder traversal
void preorder(struct Tree* root) {
    if (root != NULL) {
        printf("%d ", root->ele);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for postorder traversal
void postorder(struct Tree* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->ele);
    }
}
output:
1)insert	 2)print
1
element: 50
1)insert	 2)print
1
element: 30
1)insert	 2)print
1
element: 20
1)insert	 2)print
1
element: 40
1)insert	 2)print
1
element: 70
1)insert	 2)print
1
element: 60
1)insert	 2)print
1
element: 80
1)insert	 2)print
2
INORDER TRAVERSAL IS: 20 30 40 50 60 70 80 
POSTORDER TRAVERSAL IS: 20 40 30 60 80 70 50 
PREORDER TRAVERSAL IS: 50 30 20 40 70 60 80
