class Pair{
    public:
    Node<int> *head;
    Node<int> *tail;
    Pair(){
        head=NULL;
        tail=NULL;
    }
};

Pair constructBST_helper(BinaryTreeNode<int>* root) {
    if(root==NULL){
        Pair p;
        return p;
    }
    Pair leftOutput = constructBST_helper(root->left);
    Pair rightOutput = constructBST_helper(root->right);
    Node<int> *newNode = new Node<int>(root->data);
    if(leftOutput.head==NULL && leftOutput.tail==NULL)
    {	
        Pair _ans;
        _ans.head = newNode;
    	_ans.tail = newNode;
       	newNode->next = rightOutput.head;
        if(rightOutput.head)
        	_ans.tail=rightOutput.tail;
        return _ans;
    } else {
    	leftOutput.tail->next = newNode;
       	newNode->next = rightOutput.head;
       	if(rightOutput.head)
           	leftOutput.tail=rightOutput.tail;
    }
   	Pair ans;
   	ans.head = leftOutput.head;
   	ans.tail =leftOutput.tail ;
   	return ans;
}

Node<int>* constructBST(BinaryTreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	Pair output = constructBST_helper(root);
    return output.head;
}