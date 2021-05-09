//Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space only O(log n).

BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k){
    if(root == NULL)
        return NULL;
    BinaryTreeNode<int> *p=NULL;
    if(root->data == k){
        p= root;
    	return p;
    }
    p= searchInBST(root->left,k);
    if(p!=NULL){
        return p;
    }
    return searchInBST(root->right,k);
    return NULL;
}

void printNodesSumToSHelper(BinaryTreeNode<int> *root, int s, int *output,BinaryTreeNode<int> *root1){
    if(root==NULL){
        return;
    }
	BinaryTreeNode<int> *pair=searchInBST(root1,s-root->data);
    if(pair && root->data!=pair->data){
        output[0] = min(root->data,pair->data);
        output[1] = max(root->data,pair->data);
        pair->data=INT_MIN;
        root->data=INT_MIN;
        cout<<output[0]<<" "<<output[1]<<endl;
    }
	printNode  sSumToSHelper(root->left,s,output,root1);
    printNodesSumToSHelper(root->right,s,output,root1);
}


void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    int output[] = {-1,-1};
    printNodesSumToSHelper(root,s,output,root);
    
}