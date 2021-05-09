int length(node *head){
	node *temp = head;
    int c=0;
    while(temp!=NULL){
        temp = temp->next;
        c++;
    }
    return c;
}

node* reverse(node *head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node *temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

bool check_palindrome(node* head)
{
    //write your code here
    int size = length(head);
    if(size==1)
        return true;
	if(size==2){
        return head->data==(head->next)->data;
    }
    int mid = size/2;
    node *temp=head,*ptr=NULL;
    int i=0;
    while(i!=mid){
        ptr = temp;
        temp = temp->next;
        i++;
    }
    ptr->next = NULL;
    node *head1 = temp;
    node *h1 = reverse(head1);
    node *t1=head,*t2=h1;
    while(t1!=NULL && t2!=NULL){
        if(t1->data!=t2->data)
            return false;
        t1 = t1->next;
        t2 = t2->next;
    }
    return true;
}