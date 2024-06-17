#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
    struct node *parent;
};

int height(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct node *rightrotate(struct node *y) {
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node *leftrotate(struct node *x) {
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int balance(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    return height(root->left) - height(root->right);
}

struct node *balanceNode(struct node *root) {
    if (root == NULL) {
        return NULL;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balanceFactor = balance(root);

    if (balanceFactor > 1 && balance(root->left) >= 0) {
        return rightrotate(root);
    }

    if (balanceFactor > 1 && balance(root->left) < 0) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    if (balanceFactor < -1 && balance(root->right) <= 0) {
        return leftrotate(root);
    }

    if (balanceFactor < -1 && balance(root->right) > 0) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

struct node *minValueNode(struct node *node) {
    struct node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct node *deleteNode(struct node *root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct node *temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            struct node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    return balanceNode(root);
}

struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        root = (struct node *)malloc(sizeof(struct node));
        if (root == NULL) {
            return NULL; // Memory allocation failed
        }
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->height = 1;
        root->parent = NULL;
        return root;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
        if (root->left != NULL) {
            root->left->parent = root;
        }
    } else if (data > root->data) {
        root->right = insert(root->right, data);
        if (root->right != NULL) {
            root->right->parent = root;
        }
    } else {
        return root; // Equal data are not allowed in BST
    }

    return balanceNode(root);
}

void preOrder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct node *root = NULL;
    int choice, data;

    while (1) {
        printf("Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Preorder traversal of the AVL tree is:\n");
                preOrder(root);
                printf("NULL\n");
                break;
            case 4:
                printf("End of the program.\n");
                return 0;
            default:
                printf("Wrong input, try again.\n");
                break;
        }
    }
}
output:
Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: 
1
Enter the data to be inserted: 1
Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: 
1
Enter the data to be inserted: 2
Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: 
1
Enter the data to be inserted: 3
Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: 
1
Enter the data to be inserted: 4
Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: 
1
Enter the data to be inserted: 5
Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: 
3
Preorder traversal of the AVL tree is:
2 1 4 3 5 NULL
Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: 
2
Enter the data to be deleted: 2
Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: 
2
Enter the data to be deleted: 3
Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: 
3
Preorder traversal of the AVL tree is:
4 1 5 NULL
Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: 
2
Enter the data to be deleted: 4
Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: 
3
Preorder traversal of the AVL tree is:
5 1 NULL
Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: 
2
Enter the data to be deleted: 5
Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: 
3
Preorder traversal of the AVL tree is:
1 NULL
Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: 
2
Enter the data to be deleted: 1
Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: 
3
Preorder traversal of the AVL tree is:
NULL
Enter your choice: 1) Insert 2) Delete 3) Display 4) Exit: 
4
End of the program.


=== Code Execution Successful ===
