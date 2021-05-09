vector<int>* findPath(BinaryTreeNode<int> *root , int data){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	if(root==NULL){
        return NULL;
    }
    if(data == root->data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    else if(data < root->data){
        vector<int>* leftOutput = findPath(root->left,data);
        if(leftOutput)
            leftOutput->push_back(root->data);
        return leftOutput;
    }
    else if(data > root->data){
        vector<int>* rightOutput = findPath(root->right,data);
        if(rightOutput)
            rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
        return NULL;
}
