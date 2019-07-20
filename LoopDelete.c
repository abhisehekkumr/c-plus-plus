#include<stdio.h>
#include<stdlib.h>

struct list {
	int info;
	struct list *next;
};

struct list *crateNode(int data){
	struct list *node = (struct list *)malloc(sizeof(struct list));
	if(!node){
		printf("Memory cannot be allocated\n");
		exit(0);
	}

	node->info = data;
	node->next = NULL;
	return node;
}

void insert(struct list **head, int info){
	struct list *node = crateNode(info);
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
// this code fails when last node is pointing to the first node
void makeLoop(struct list **head){
	if(*head==NULL)
		return;

	int loc = 9;
	struct list *ptr = *head;
	while(ptr!=NULL && --loc)
		ptr = ptr->next;

	struct list *temp = ptr;
	printf("Temporary %d \n",temp->info);
	while(ptr->next!=NULL)
		ptr = ptr->next;

	ptr->next = temp;
}

void detect(struct list *head){
	struct list *fast = head->next;
	struct list *slow = head;

	int flag = 0;
	if(head==NULL)
		return;
	if(head->next==NULL)
		return;

	while(fast!=NULL && fast->next!=NULL){
		if(slow == fast){
			flag = 1;
			break;
		}
		slow = slow->next;
		fast = fast->next->next;
	}

	if(flag)
		printf("Yes %d\n",fast->info);
	else
		printf("No\n");
}

void middle(struct list *head){
	struct list *fast = head;
	struct list *slow = head;

	while(fast && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}

	printf("The middle element is %d \n",slow->info);
}

void loopElement(struct list **head){
	struct list *slow = *head;
	struct list *fast = (*head)->next;
	struct list *ptr = *head;
	while(slow && fast && fast->next){
		
		slow = slow->next;
		fast = fast->next->next;
		ptr = fast;
		if(slow==fast)
			break;
	}

	slow = *head;

	while(slow!=fast->next){
		slow = slow->next;
		fast=fast->next;
	}
	fast->next = NULL;
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
	insert(&head,15);
	insert(&head,16);
	insert(&head,17);
	//insert(&head,16);
	traverse(head);
	makeLoop(&head);
	//traverse(head);
	//detect(head);
	//middle(head);
	//loopElement(head);
	//detect(head);
	printf("Magic starts\n");
	loopElement(&head);
	traverse(head);
}