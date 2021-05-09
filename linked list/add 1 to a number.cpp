/* Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
Note: You don't need to print the elements, just update the elements and return the head of updated LL. */

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node* reverse(Node *head){
	if(head==NULL || head->next==NULL)
        return head;
    Node *ptr = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return ptr;
}

Node* NextLargeNumber(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    Node *hnew = reverse(head);
    Node *temp = hnew, *prev=NULL;
    int carry=1,sum=0;
    while(temp!=NULL){
        sum = carry+temp->data;
        carry = (sum>=10)?1:0;
        temp->data = sum%10;
        prev = temp;
        temp = temp->next;
    }
    if(carry)
        prev->next = new Node(carry);
    return reverse(hnew);
}