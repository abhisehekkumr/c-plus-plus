#include<stdio.h>
#include<stdlib.h>

struct list {
	int info;
	struct list *next;
};

struct list *createNode(int data){
	struct list *node = (struct list *)malloc(sizeof(struct list));
	if(!node){
		printf("memeory error cannnot allocate memory to node\n");
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

struct list *merge(struct list **head,struct list *list1,struct list *list2){
	struct list *ptr = *head;
	if(list1->info<=list2->info){
		struct list *node = (struct list *)malloc(sizeof(struct list));
		node->info = list1->info;
		node->next = NULL;
		list1 = list1->next;
		ptr = node;
		//printf("in first %d ",list1->info);
	}else{
		struct list *node = (struct list *)malloc(sizeof(struct list));
		node->info = list2->info;
		node->next = NULL;
		ptr = node;
		list2 = list2->next;
		//printf("in second %d ",list2->info);
	}

	while(list1 && list2){
		struct list *node = (struct list *)malloc(sizeof(struct list));
		if(list1->info<=list2->info){
			node->info = list1->info;
			node->next = NULL;
			printf("%d ",node->info);
			ptr->next = node;
			ptr = node;
			list1 = list1->next;
		}else{
			node->info = list2->info;
			node->next = NULL;
			printf("%d ",node->info);
			ptr->next = node;
			ptr = node;
			list2 = list2->next;
		}
	}

	while(list1){
		struct list *node = (struct list *)malloc(sizeof(struct list));
		node->info = list1->info;
		node->next = NULL;
		printf("%d ",node->info);
		ptr->next = node;
		ptr = node;
		list1 = list1->next;
	}

	while(list2){
		struct list *node = (struct list *)malloc(sizeof(struct list));
		node->info = list2->info;
		node->next = NULL;
		printf("%d ",node->info);
		ptr->next = node;
		ptr = node;
		list2 = list2->next;
	}
	return *head;
}

int main(){
	struct list *list1 = NULL;
	insert(&list1,10);
	insert(&list1,20);
	insert(&list1,30);
	struct list *list2 = NULL;
	insert(&list2,15);
	insert(&list2,17);
	printf("ok\n");
	traverse(list1);
	traverse(list2);
	struct list *head = NULL;
	head =  merge(&head,list1,list2);
	traverse(head);
}