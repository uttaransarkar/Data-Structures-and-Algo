// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
node *findMid(node *head){
    node *temp1 = head,*temp2 = head->next;
    while(temp2!=NULL && temp2->next!=NULL){
        temp1 = temp1->next;
        temp2 = temp2->next->next;
    }
    return temp1;
}

node* merge(node *head1, node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    node *fhead=NULL,*ftail=NULL;
    while(head1!=NULL && head2!=NULL){
        if(fhead==NULL){
            fhead = (head1->data < head2->data)?head1:head2;
            ftail = fhead;
            fhead == head1 ? head1 = head1->next : head2 = head2->next;
        } else {
            if(head1->data < head2->data){
                ftail->next = head1;
                ftail = head1;
                head1 = head1->next;
            } else {
                ftail->next = head2;
                ftail = head2;
                head2 = head2->next;
            }
        }
    }
    if(head1!=NULL)
        ftail->next = head1;
    if(head2!=NULL)
        ftail->next= head2;
    return fhead;
}

node* mergeSort(node *head) {
    //write your code here
    if(head==NULL||head->next == NULL)
        return head;
    node *mid = findMid(head);
    node *hnew = mid->next;
    mid->next = NULL;
    node *h1 = mergeSort(head);
    node *h2 = mergeSort(hnew);
    node *fhead = merge(h1,h2);
    return fhead;
}
