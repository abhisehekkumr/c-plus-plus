#include<stdio.h>
#include<stdlib.h>

struct list {
  int info;
  struct list *next;
};

struct list *createNode(int data){
  struct list *node = (struct list *)malloc(sizeof(struct list));

  if(!node){
    printf("memory cannot be allocated\n");
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

  while(ptr!=NULL){
    printf("%d ",ptr->info);
    ptr = ptr->next;
  }

  printf("\n");
}

void getMiddle(struct list *head){
  struct list *slow = head;
  struct list *fast = head;

  if(head==NULL){
    printf("List is empty\n");
    return;
  }

  if(head->next==NULL)  {
    printf("%d",head->info);
    return;
  }

  while (fast!=NULL && fast->next!=NULL) {
      slow = slow->next;
      fast = fast->next->next;
  }

  printf("The middle node is : %d\n",slow->info);
}

int main(){
  struct list *head = NULL;
  insert(&head,1);
  insert(&head,2);
  insert(&head,3);
  insert(&head,4);
  insert(&head,5);
  traverse(head);
  getMiddle(head);
}
