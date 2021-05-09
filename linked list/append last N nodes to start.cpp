node* append_LinkedList(node* head,int n)
{
    //write your code here
    node *temp=head,*temp1=head;
    int size=0,i=0;
    while(temp!=NULL){
        temp=temp->next;
        size++;
    }
    while(i!=size-n-1){
        temp1= temp1->next;
        i++;
    }
    node *head1 = temp1->next;
    temp1->next = NULL;
    node *temp2 = head1,*curr=NULL;
    while(temp2!=NULL){
        curr = temp2;
        temp2 = temp2->next;
    }
    curr->next = head;
    return head1;
}
a