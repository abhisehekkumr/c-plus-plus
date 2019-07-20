#include<stdio.h>
#include<stdlib.h>

struct list {
    int info;
    struct list *next;
};

struct list *createNode(int data){
    struct list *node = (struct list *)malloc(sizeof(struct list));
    if(!node){
        printf("Cannot allocate memory to the node\n");
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

struct list *removeDuplicate(struct list *head){
	struct list *ptr = head;
	struct list *ahead = head->next;

	while(ahead){
		if(ahead->info == ptr->info){
			struct list *temp = ahead;
			ahead = ahead->next;
			ptr->next = temp->next;
			free(temp);
		}else{
			ptr = ptr->next;
			ahead = ahead->next;
		}
	}
	//ptr->next = NULL;
	return head;
}

struct list *remove1(struct list *head){
	struct list *ptr_main = head;

	if(!ptr_main)
		return NULL;
	if(!ptr_main->next)
		return ptr_main;

	while(ptr_main){
		int element = ptr_main->info;
		struct list *ptr = ptr_main;
		struct list *ahead = ptr_main->next;
		while(ahead){

			if(ahead->info == element){
				struct list *mm = ahead;
				printf("%d\n",ahead->info);
				ahead = ahead->next;
				ptr->next = ahead;
				free(mm);
			}else{
				ptr = ptr->next;
				ahead = ahead->next;
			}
		}
		ptr_main = ptr_main->next;
	}
	return ptr_main;
}

int main(){
	struct list *head = NULL;
	insert(&head,2);
	insert(&head,2);
	insert(&head,2);
	insert(&head,2);
	insert(&head,21);
	insert(&head,43);
	insert(&head,43);
	insert(&head,60);

	printf("\n old list\n");
	traverse(head);
	struct list *new = removeDuplicate(head);
	printf("\n New list\n");
	traverse(new);

	struct list *unorded = NULL;
	insert(&unorded,5);
	insert(&unorded,2);
	insert(&unorded,2);
	insert(&unorded,4);
	//traverse(unorded);
	struct list *show = remove1(unorded);
	printf("un-orded\n");
	traverse(show);
}