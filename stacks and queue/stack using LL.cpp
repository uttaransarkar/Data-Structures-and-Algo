template <typename T> 
class Stack {
    Node<T> *head; 
    int size; // number of elements prsent in stack 
    public : 
    Stack() { 
        head=NULL; 
        size=0; 
    } 
    int getSize() { 
        return size; 
    } 
    bool isEmpty() { 
        if(size==0) 
            return true; 
        else return false; 
    } 
    void push(T element) { 
        Node<T> *newnode=new Node<T>(element); 
        if(head==NULL) 
            head=newnode; 
        else{ 
            newnode->next=head; 
            head=new node; 
        } 
        size++; 
    } 
    T pop() { // Return 0 if stack is empty. Don't display any other message 
        if(head==NULL) 
            return 0; 
        T ans=head->data; 
        Node<T> *a=head; 
        head=head->next; 
        delete a; 
        size--; 
        return ans; 
    } 
    T top() { // Return 0 if stack is empty. Don't display any other message 
        if(head == NULL) 
            return 0; 
        return head->data; 
    } 
};