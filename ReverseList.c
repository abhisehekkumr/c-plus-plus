#include<stdio.h>
#include<stdlib.h>

struct list {
	int info;
	struct list *next;
};

struct list *createNode(int info){
	struct list *node = (struct list *)malloc(sizeof(struct list));
	if(!node){
		printf("Memory cannot be allocated\n");
		exit(0);
	}

	node->info = info;
	node->next = NULL;
	return node;
}

void insert(struct list **head,int data){
	struct list *node = createNode(data);
	struct list *ptr = *head;

	if(!(*head)){
		*head = node;
		return;
	}

	while(ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = node;
}

void traverse(struct list *head){
	struct list *ptr = head;

	while(ptr!=NULL){
		printf("%d ",ptr->info);
		ptr = ptr->next;
	}

	printf("\n");
}

struct list *Reverse(struct list *head){
	struct list *current = head;
	struct list *next = NULL;
	struct list *prev = NULL;

	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return prev;
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
	traverse(head);

	printf("Reverse of the above list is below\n");
	head = Reverse(head);
	traverse(head);
}
