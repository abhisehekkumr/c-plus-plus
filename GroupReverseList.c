#include<stdio.h>
#include<stdlib.h>

struct list {
	int info;
	struct list *next;
};

struct list *createNode(int data){
	struct list *node = (struct list *)malloc(sizeof(struct list));
	if(!node){
		printf("memory error\n");
		exit(0);
	}
	node->info = data;
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

struct list *reverse(struct list *head,int k){

	struct list *current = head;
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
		head->next = reverse(next,k);
	return prev;
}

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		struct list *head = NULL;
		int number,element,k;
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


		printf("Enter the value for k\n");
		scanf("%d",&k);
		printf("\n origial list \n");
		traverse(head);
		printf("\nreversed list\n");
		struct list *ptr = reverse(head,k);
		traverse(ptr);
	}
}