//head is the head of the linked list, n is number of elements to be reversed
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
class HT{
    public:
    node *head;
    node *tail;
    HT(){
        head=NULL;
        tail=NULL;
    }
    HT(node *a, node *b){
        head = a;
        tail = b;
    }
};

HT reverse(node *head){
    node *curr = head, *prev = NULL, *next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    HT ht = HT(prev,head);
    return ht;
}

node* kReverse(node* head,int n)
{
    //write your code here
    if(n<=0)
        return head;
    if(head == NULL||head->next == NULL)
        return head;
    
    node *t = head;int c=1;
    while(t->next!=NULL && c!=n){
        t = t->next;
        c++;
    }
    node *h2 = t->next;
    t->next = NULL;
    HT headtail = reverse(head);
    head = headtail.head;
    t = headtail.tail;
    node *h = kReverse(h2,n);
    t->next = h;
    return head;
}
    
