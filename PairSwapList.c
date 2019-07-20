#include<stdio.h>
#include<stdlib.h>

struct list {
	int info;
	struct list *next;
};

struct list *createNode(int data){
	struct list *node = (struct list *)malloc(sizeof(struct list));
	if(!node){
		printf("Error\n");
		return NULL;
	}
	node->info = data;
	node->next = NULL;
	return node;
}

void insert(struct list **head,int info){
	struct list *node = createNode(info);
	struct list *ptr = *head;

	if(!(*head)){
		*head  = node;
		return;
	}

	while(ptr->next)
		ptr = ptr->next;
	ptr->next = node;
}

void traverse(struct list *head){
	struct list *ptr = head;
	if(head){
		while(ptr){
			printf("%d ",ptr->info);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

struct list *revers1(struct list **head,int k){
	struct list *current = *head;
	struct list *next = NULL;
	struct list *prev = NULL;
	int count = 0;

	while(current && count<k){
		count++;
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	if(next)
		(*head)->next = revers1(&next,2);
	return prev;
}

int main(){
	struct list *head =  NULL;
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
	insert(&head,15);
	printf("\nbefore reverse\n");
	traverse(head);
	printf("\nafter reverse\n");
	struct list *new_head = revers1(&head,2);
	traverse(new_head);
}