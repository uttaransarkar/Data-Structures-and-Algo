BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int *inorder, int inStart, int inEnd, int postStart, int postEnd) {
	if (inStart > inEnd) 
        return NULL; 
    
    int rootData = postorder[postEnd];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    if (inStart == inEnd) 
        return root; 
    
    int rootIndex = -1; 
    for(int i=inStart;i<=inEnd;i++){
        if(inorder[i]==rootData){
            rootIndex = i;
            break;
        }
    }
    
    root->left = getTreeFromPostorderAndInorder(postorder, inorder, inStart, rootIndex-1, postStart, postStart + rootIndex - (inStart + 1)); 
    root->right = getTreeFromPostorderAndInorder(postorder, inorder, rootIndex+1, inEnd, postStart+rootIndex-inStart, postEnd-1); 
    
  
    return root; 
}

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
	return getTreeFromPostorderAndInorder(postorder, inorder, 0, inLength-1, 0, postLength-1);
}
