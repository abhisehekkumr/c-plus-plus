#include<stdio.h>
#include<stdlib.h>

struct list {
	int info;
	struct list *next;
};

struct list *createNode(int data){
	struct list *node = (struct list *)malloc(sizeof(struct list));
	if(!node){
		printf("Memory cannot be allocated\n");
		exit(0);
	}
	node->info = data;
	node->next = NULL;
	return node;
}

void insert(struct list **head,int info){
	struct list *node = createNode(info);
	struct list *ptr = *head;

	if(!(*head)){
		*head = node;
		return;
	}

	while(ptr->next!=NULL)
		ptr = ptr->next;
	ptr->next = node;
}

void traverse(struct list *head){
	struct list *ptr = head;

	if(head){
		while(ptr!=NULL){
			printf("%d ",ptr->info);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

void findNode(struct list *head,int number){
	struct list *node = head;
	struct list *not_node = head;

	if(number == 0){
		printf("Not a location \n");
		return;
	}

	while(not_node && number--)
		not_node = not_node->next;
	if(not_node==NULL){
		printf("Number is greater than the total number of nodes in the linked list\n");
		return;
	}

	while(not_node){
		node = node->next;
		not_node = not_node->next;
	}

	printf("node is %d \n",node->info);
}
int main(){
	struct list *head = NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	insert(&head,5);
	insert(&head,6);
	insert(&head,7);
	insert(&head,8);
	insert(&head,9);
	insert(&head,10);
	insert(&head,11);
	insert(&head,12);
	insert(&head,13);
	insert(&head,14);
	printf("The linked list is \n");
	traverse(head);

	int t;
	scanf("\n%d",&t);
	while(t--){
		printf("N=");
		int number;
		scanf("\n%d",&number);
		findNode(head,number);
	}
}