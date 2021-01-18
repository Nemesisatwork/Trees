/*Implement binary search tree with following functions:

1. Insert in BST
2. Delete from BST
3. Search in BST
4. Check if BST is an AVL Tree
*/
#include<stdio.h>
#include<stdlib.h>
struct node						//blueprint of the nodes
{
	int data;
	struct node* left;
	struct node* right;
}*root,*ptr;						//global variables
struct node* create_node(int item) 			//function to create a node and return it
{ 
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
//function to insert a new node in BST

struct node* insert_node(struct node* ptr, int e) 
{ 
    /* If the tree is empty, return a new node */
    if (ptr == NULL) 
        return create_node(e); 
  
    /* Otherwise, recurse down the tree */
    if (e<ptr->data) 
        ptr->left = insert_node(ptr->left, e); 
    else if (e>ptr->data) 
        ptr->right = insert_node(ptr->right, e); 
  
    return ptr; 
} 

//function to search the min possible value after the root node

struct node* min_node()
{
	struct node *temp;
	temp=root->right;
	while(temp!=NULL&&temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}

//function to delete a node
struct node* delete_node(struct node* ptr, int e)
{
    // base case
    if (ptr == NULL)
        return ptr;
 
    // If element is smaller
    if (e < ptr->data)
        ptr->left = delete_node(ptr->left, e);
 
    // If element is greater
    else if (e > ptr->data)
        ptr->right = delete_node(ptr->right, e);
 
    // if element found
    else {
        // node with only one child or no child
        if (ptr->left == NULL) {
            struct node* temp = ptr->right;
            free(ptr);
            return temp;
        }
        else if (ptr->right == NULL) {
            struct node* temp = ptr->left;
            free(ptr);
            return temp;
        }
 
        // node with two children: 
    	//finding the smallest number in the right subtree for replacement
        struct node* temp = min_node();
 
        //changing root value
        ptr->data = temp->data;
 
        // Delete the node which was replaced
        ptr->right = delete_node(ptr->right, temp->data);
    }
    return ptr;
}

//function to search for a node

struct node* search_node(struct node* ptr, int e) 
{ 
    //if element is present at root 
    if (ptr==NULL || ptr->data == e)
    	return ptr;

    // element is greater than root
    else if (ptr->data < e) 
       	return search_node(ptr->right, e);
    
    // element is smaller than root
    else if (ptr->data > e) 
    	return search_node(ptr->left, e);
    return 0;
}

int height(struct node* node); 			//function declaration

//function to check if tree is AVL or not  
int isBalanced(struct node* root) 
{ 
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */
  
    /* If tree is empty then return true */
    if (root == NULL) 
        return 1; 
  
    /* Get the height of left and right sub trees */
    lh = height(root->left); 
    rh = height(root->right); 
  
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) 
        return 1; 
  
    return 0; 
} 
  
/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */
  
/* returns maximum of two integers */
int max(int a, int b) 
{ 
	if(a>=b)
		return a;
	else
		return b;
    //return (a >= b) ? a : b; 
} 
  
int height(struct node* node) 
{ 
    if (node == NULL) 
        return 0; 
    
    //returning the height of the tree
    return 1 + max(height(node->left), height(node->right)); 
}

//functions to display the tree
void inorder(struct node* ptr) 
{ 
    if (ptr != NULL) 
    { 
        inorder(ptr->left); 
        printf("\t%d\t", ptr->data); 
        inorder(ptr->right); 
    } 
} 
void preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf("\t%d\t",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("\t%d\t",ptr->data);
	}
}

int main()
{
	int ele,ch;
	struct node* temp;
	temp=NULL;
	root=NULL;
	while(1)
	{
		printf("\n******** MAIN MENU ******** \n\n1. Insert an element\n2. Delete an element\n3. Search for an element\n4. AVL check\n5. Display Inorder traversal\n6. Display Preorder traversal\n7. Display Postorder traversal\n8. Exit\n\nEnter your choice- ");
		scanf("%d",&ch);
		printf("\n***************************");
		switch(ch)
		{
			case 1: printf("\nEnter the element to be inserted- ");
					scanf("%d",&ele);
					root=insert_node(root,ele);
					break;

			case 2: printf("\nEnter the element to be deleted- ");
					scanf("%d",&ele);
					root=delete_node(root,ele);
					break;

			case 3: printf("\nEnter the element to be searched-  ");
					scanf("%d",&ele);
					temp=search_node(root,ele);
					if(temp==NULL)
					{
						printf("\nElement not found!");
					}
					else
					{
						printf("\nElement found!");
					}
					break;

			case 4:	if (isBalanced(root)) 
					printf("\nThe tree is an AVL\n");
					else
					printf("\nThe tree is not an AVL\n"); 
					break;
			
			case 5: printf("\nInorder- ");                  
					inorder(root);  
					printf("\n");
					break;

			case 6: printf("\nPostorder- ");
					postorder(root); 
					printf("\n");
					break;

			case 7: printf("\nPreorder- ");
					preorder(root);
					printf("\n");
					break;
		
			case 8: exit(1);
					break;

			default: printf("\nInvalid choice!");
		}
	}
   	return 0;
}
