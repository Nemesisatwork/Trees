#include<stdio.h>
#include<stdlib.h>
int sum;

//blueprint of the tree node
struct node
{
	int data;
	struct node *left;
	struct node *right;
}*root,*ptr;

//for creating the root node
void create_root(int e)										
{
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=e;													
	ptr->left=NULL;
	ptr->right=NULL;
	
	//assigning root as ptr
	root=ptr;
}

//for insertion of nodes accordingly
void insert_node_left()
{
	struct node *temp,*prev,*newptr;
	int ele,flag=1;
	char ch;

	if(root->left==NULL)
	{
		printf("\nEnter left child of root (0 for no child)- ");
		scanf("%d",&ele);
		if(ele!=0)
		{
			newptr=(struct node*)malloc(sizeof(struct node));
			newptr->data=ele;													
			newptr->left=NULL;													
			newptr->right=NULL;
			root->left=newptr;

			//intialising sum to zero
			sum=0;	
		}
	}
	if(root->right==NULL)
	{
		printf("\nEnter right child of root (0 for no child)- ");
		scanf("%d",&ele);
		if(ele!=0)
		{
				
			//creating a node and assigning the right to it
			newptr=(struct node*)malloc(sizeof(struct node));
			newptr->data=ele;													
			newptr->left=NULL;	
			newptr->right=NULL;												
			root->right=newptr;

			//intialising sum to zero
			sum=0;	
		}
	}
	temp=root->left;

	//traversing the tree
	while(temp!=NULL)
	{
		
		//if the left link is empty
		if(temp->left==NULL)
		{
			printf("\nEnter left child of %d (0 for no child)- ",temp->data);
			scanf("%d",&ele);
			if(ele!=0)
			{
				
				//creating a node and assigning the left link to it
				ptr=(struct node*)malloc(sizeof(struct node));
				ptr->data=ele;													
				ptr->left=NULL;													
				ptr->right=NULL;
				temp->left=ptr;

				//intialising sum to zero
				sum=0;		
			}
		}

		//if the  right link is empty
		if(temp->right==NULL)
		{
			printf("\nEnter right child of %d (0 for no child)- ",temp->data);
			scanf("%d",&ele);
			if(ele!=0)
			{
				
				//creating a node and assigning the right to it
				ptr=(struct node*)malloc(sizeof(struct node));
				ptr->data=ele;													
				ptr->left=NULL;	
				ptr->right=NULL;												
				temp->right=ptr;

				//intialising sum to zero
				sum=0;	
			}
		}
		getchar();
		printf("\nDo you want to continue? (y/n)- ");
		scanf("%c",&ch);
		if(ch=='y')
		{
			if(flag%2==0)
			{
				temp=prev->right;
			}
			if(temp->left!=NULL && temp->right!=NULL)
			{
				prev=temp;
				temp=temp->left;
				flag++;
			}
			else if(temp->left!=NULL && temp->right==NULL)
			{
				temp=temp->left;
			}
			else if(temp->left==NULL && temp->right!=NULL)
			{
				temp=temp->right;
			}
		}
		else
			break;
	}
}
void insert_node_right()
{
	struct node *temp,*prev,*newptr;
	int ele,flag=1;
	char ch;

	if(root->left==NULL)
	{
		printf("\nEnter left child of root (0 for no child)- ");
		scanf("%d",&ele);
		if(ele!=0)
		{
			newptr=(struct node*)malloc(sizeof(struct node));
			newptr->data=ele;													
			newptr->left=NULL;													
			newptr->right=NULL;
			root->left=newptr;

			//intialising sum to zero
			sum=0;		
		}
	}
	if(root->right==NULL)
	{
		printf("\nEnter right child of root (0 for no child)- ");
		scanf("%d",&ele);
		if(ele!=0)
		{
				
			//creating a node and assigning the right to it
			newptr=(struct node*)malloc(sizeof(struct node));
			newptr->data=ele;													
			newptr->left=NULL;	
			newptr->right=NULL;												
			root->right=newptr;

			//intialising sum to zero
			sum=0;	
		}
	}
	temp=root->right;

	//traversing the tree
	while(temp!=NULL)
	{
		

		//if the left link is empty
		if(temp->left==NULL)
		{
			printf("\nEnter left child of %d (0 for no child)- ",temp->data);
			scanf("%d",&ele);
			if(ele!=0)
			{
				
				//creating a node and assigning the left link to it
				ptr=(struct node*)malloc(sizeof(struct node));
				ptr->data=ele;													
				ptr->left=NULL;													
				ptr->right=NULL;
				temp->left=ptr;

				//intialising sum to zero
				sum=0;	
			}
		}

		//if the  right link is empty
		if(temp->right==NULL)
		{
			printf("\nEnter right child of %d (0 for no child)- ",temp->data);
			scanf("%d",&ele);
			if(ele!=0)
			{
				
				//creating a node and assigning the right to it
				ptr=(struct node*)malloc(sizeof(struct node));
				ptr->data=ele;													
				ptr->left=NULL;
				ptr->right=NULL;													
				temp->right=ptr;

				//intialising sum to zero
				sum=0;	
			}
		}
		getchar();
		printf("\nDo you want to continue? (y/n)- ");
		scanf("%c",&ch);
		if(ch=='y')
		{	if(flag%2==0)
			{
				temp=prev->right;
			}
			if(temp->left!=NULL && temp->right!=NULL)
			{
				prev=temp;
				temp=temp->left;
				flag++;
			}
			else if(temp->left!=NULL && temp->right==NULL)
			{
				temp=temp->left;
			}
			else if(temp->left==NULL && temp->right!=NULL)
			{
				temp=temp->right;
			}
		}
		else
			break;
	}
}
int calc_sum(struct node *ptr)
{
	if(ptr!=NULL)
	{	
		if(ptr->left!=NULL||ptr->right!=NULL)
		{
			sum=sum+ptr->data;
		 	if(ptr->left!=NULL)
			{
				calc_sum(ptr->left);
			}
			calc_sum(ptr->right);
		}
	}
	return sum;
		
}
void inorder(struct node *ptr)
{
	//displaying in inorder form
	
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf("%d\t",ptr->data);
		inorder(ptr->right);
	}
}
void preorder(struct node *ptr)
{
	//displaying in preorder form

	if(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
void postorder(struct node *ptr)
{
	//displaying in postorder form
	
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d\t",ptr->data);
	}
}
int main()
{
	int e,ch,S;
	root=NULL;
	
	//reading the root node
	printf("\nEnter root node- ");
	scanf("%d",&e);
	create_root(e);
	if(root==NULL)
		exit(0);
	
	//menu driven conditions
	while(1)
	{
		printf("\n****************MENU**************\n1. Enter in left subtree\n2. Enter in right subtree\n3. Preorder traversal\n4. Inorder traversal\n5. Postorder traversal\n6. Calculate the sum of non-leaf nodes\n7. Exit\n\n Enter your choice- ");
		scanf("%d",&ch);
		printf("\n**********************************");
		switch(ch)
		{
			case 1: 
					//inserting in left subtree
					insert_node_left();
					break;
			case 2: 
					//inserting in right subtree
					insert_node_right();
					break;
			case 3: printf("\nThe preorder traversal is as- ");
					preorder(root);
					break;
			case 4: printf("\nThe inorder traversal is as- ");
					inorder(root);
					break;
			case 5: printf("\nThe postorder traversal is as- ");
					postorder(root);
					break;
			case 6: S=calc_sum(root);
					printf("\nThe sum is- %d",S);
					if(S%2==0)
					{
						printf(" which is even");
					}
					else
					{
						printf(" which is odd");
					}
					break;
			case 7: exit(1);
					break;
			default: printf("\nInvalid choice!");
		}
	}
	return 0;
}