#include<stdio.h>
#include<stdlib.h>

struct list {
	int info;
	struct list *next;
};

struct list *createNode(int data){
	struct list *node = (struct list *)malloc(sizeof(struct list));
	if(!node){
		printf("Cannot allocate memory\n");
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

struct list *merge(struct list *head1, struct list *head2){
	struct list *node = (struct list *)malloc(sizeof(struct list));
	if(head1==NULL)
		return head2;
	if(head2 == NULL)
		return head1;
	if(head1->info<=head2->info){
		node = head1;
		node->next = merge(head1->next,head2);
	}else{
		node = head2;
		node->next = merge(head1,head2->next);
	}
	return node;
}

int main(){
	struct list *head1 = NULL;
	insert(&head1,4);
	insert(&head1,4);
	insert(&head1,5);
	insert(&head1,8);
	insert(&head1,40);
	insert(&head1,45);
	insert(&head1,48);
	struct list *head2 = NULL;
	insert(&head2,1);
	insert(&head2,2);
	insert(&head2,4);
	insert(&head2,7);
	insert(&head2,490);
	insert(&head2,590);
	struct list *list1 = merge(head1,head2);
	traverse(list1);

}