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

void joint(struct list *head, struct list *head1){
    struct list *ptr = head;
    struct list *ptr2 = head1;

    while(ptr2->next){
        ptr2 = ptr2->next;
        ptr = ptr->next;
    }

    ptr2->next = ptr;
}


int getCount(struct list *head){
    struct list *ptr = head;
    int count = 0;

    while(ptr){
        count++;
        ptr = ptr->next;
    }
    return count;
}

int mergePoint(int d, struct list *head1,struct list *head2){
    struct list *ptr1 = head1;
    struct list *ptr2 = head2;

    for(int i=0;i<d;i++){
        if(!ptr1)
            return -1;
        ptr1 = ptr1->next;
    }

    while(ptr1 && ptr2){
        if(ptr2 == ptr1)
            return ptr1->info;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

void findMergePoint(struct list *head1,struct list *head2){
    int first = getCount(head1);
    int second = getCount(head2);

    if(first > second)
        printf("\n The merging Point is %d\n",mergePoint(first-second,head1,head2));
    else
        printf("\nThe merging point is %d\n",mergePoint(second-first,head2,head1));
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

    struct list *head1 = NULL;
    insert(&head1,45);
    insert(&head1,23);
    insert(&head1,16);
    insert(&head1,145);
    insert(&head1,2);
    insert(&head1,16);
    insert(&head1,1456);
    insert(&head1,1345);

    joint(head,head1);
    printf("first list\n");
    traverse(head);
    printf("second list\n");
    traverse(head1);

    printf("\n\n\n\n\n");
    findMergePoint(head,head1);
}