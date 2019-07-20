#include<stdio.h>
#include<stdlib.h>

struct Node{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
	int size_of_tree;
};

struct Node *newNode(int key){
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));

	if(!node)
		return NULL;
	node->key = key;
	node->height = 1;
	node->size_of_tree = 1;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int max(int a, int b){ 
	return (a > b )? a : b;
}

int height(struct Node *root){
	if(root == NULL)
		return 0;
	return root->height;
}

int size(struct Node *root){

	if(root == NULL)
		return 0;
	return root->size_of_tree;
}


struct Node *rightRotate(struct Node *y){
	struct Node *x = y->left; 
    struct Node *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
  
    // Update sizes 
    y->size_of_tree = size(y->left) + size(y->right) + 1; 
    x->size_of_tree = size(x->left) + size(x->right) + 1; 
  
    // Return new root 
    return x; 
}

struct Node *leftRotate(struct Node *x){
	struct Node *y = x->right; 
    struct Node *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    // Update sizes 
    x->size_of_tree = size(x->left) + size(x->right) + 1; 
    y->size_of_tree = size(y->left) + size(y->right) + 1; 
  
    // Return new root 
    return y;
}


int getBalance(struct Node *root){
	if(root == NULL)
		return 0;
	return height(root->left) - height(root->right);
}

struct Node *insert(struct Node *root, int key, int *count){
	if(root == NULL )
		return (newNode(key));
	else if(root->key > key)
		root->left = insert(root->left, key, count);
	else if(root->key < key){
		root->right = insert(root->right, key, count);
		*count = *count + size(root->left) + 1;
	}

	root->height = max(height(root->left), height(root->right)) + 1;
	root->size_of_tree = size(root->left) + size(root->right) + 1;

	int balance = getBalance(root);

	if(balance > 1 && root->left->key  > key)
		return rightRotate(root);

	else if(balance < -1 && root->right->key < key)
		return leftRotate(root);

	else if(balance > 1 && key > root->left->key){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	else if(balance < -1 && root->right->key  < key){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void constructArray(int arr[], int counts[], int n){

	struct Node *root = NULL;
	for(int i = 0; i < n; i++)
		counts[i] = 0;

	for(int i = n-1; i >= 0; i--)
		root = insert(root, arr[i], &counts[i]);
}

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);

		int arr[n];

		for(int i = 0; i<n; i++)
			scanf("%d",&arr[i]);

		int *counts = (int *)malloc(sizeof(int)*n);
		constructArray(arr,counts,n);

		for(int i = 0; i<n; i++)
			printf("%d ",counts[i]);
		printf("\n");
	}
}