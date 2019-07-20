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

void insert(struct list **head,int data){
	struct list *node = createNode(data);
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

	while(ptr!=NULL){
		printf("%d ",ptr->info);
		ptr = ptr->next;
	}

	printf("\n");
}

void makeLoop(struct list **head){
	int k=12;
	struct list *ptr = *head;

	while(ptr!=NULL && --k)	
		ptr = ptr->next;
	struct list *temp = ptr;

	while(ptr->next!=NULL)
		ptr = ptr->next;
	ptr->next = temp;
}

void detectLoop(struct list *head){
	struct list *slow = head;
	struct list *fast = head->next;

	if(!head)
		return;

	if(head->next == NULL)
		return;
	
	while(fast!=NULL){
		slow = slow->next;

		if(fast->next==NULL){
			printf("No\n");
			return;
		}

		fast = fast->next->next;

		if(fast==slow){
			printf("Yes\n");
			return;
		}
	}

	return;
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
	traverse(head);
	//makeLoop(&head);
	//traverse(head);
	detectLoop(head);
}