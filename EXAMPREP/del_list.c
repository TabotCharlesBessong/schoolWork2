

struct node* delete(struct node *head){
  struct node *temp = head;
  while(temp != NULL){
    temp = temp->link;
    free(head);
    head = temp
  }
  return head;
}