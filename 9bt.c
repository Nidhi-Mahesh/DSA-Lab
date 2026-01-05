#include <stdio.h>
#include <stdlib.h>

/*
struct
create_node
create_tree
display
count_nodes
height
leaf_nodes
nonleaf_nodes
main
*/

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node* NODE;

/* Create node */
NODE create_node(int item)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* Create tree using user input */
NODE create_tree()
{
    int item;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &item);

    if (item == -1)
        return NULL;

    NODE root = create_node(item);

    printf("Enter left child of %d\n", item);
    root->left = create_tree();

    printf("Enter right child of %d\n", item);
    root->right = create_tree();

    return root;
}

/* Inorder traversal */
void display(NODE root)
{
    if (root != NULL) {
        display(root->left);
        printf("%d\t", root->data);
        display(root->right);
    }
}

/* Count nodes */
int count_nodes(NODE root)
{
    if (root == NULL)
        return 0;
    return count_nodes(root->left) + count_nodes(root->right) + 1;
}

/* Height */
int height(NODE root)
{
    if (root == NULL)
        return -1;

    int lh = height(root->left);
    int rh = height(root->right);

    return (lh > rh ? lh : rh) + 1;
}

/* Leaf nodes */
int leaf_nodes(NODE root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    return leaf_nodes(root->left) + leaf_nodes(root->right);
}

/* Non-leaf nodes */
int nonleaf_nodes(NODE root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;

    return nonleaf_nodes(root->left) + nonleaf_nodes(root->right) + 1;
}

int main()
{
    NODE root;

    printf("Create Binary Tree\n");
    root = create_tree();

    printf("\nInorder traversal:\n");
    display(root);

    printf("\n\nTotal nodes = %d", count_nodes(root));
    printf("\nHeight = %d", height(root));
    printf("\nLeaf nodes = %d", leaf_nodes(root));
    printf("\nNon-leaf nodes = %d\n", nonleaf_nodes(root));

    return 0;
}
