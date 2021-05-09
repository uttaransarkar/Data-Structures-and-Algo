// Following is the node structure
/**************
class Node{
public:
    int data;
    Node * next;
    Node(int data){
        this->dSata=data;
        this->next=NULL;
    }
};
Node* insertNodeRec(Node *head, int i, int data) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(head==NULL && i!=0)
         return head;
    if(i==0){
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *temp = insertNodeRec(head->next,i-1,data);
    head->next = temp;
    return head;
    
}