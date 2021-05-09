int lcaInBST(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
	if(root==NULL)
        return -1;
    if(root->data>val1 && root->data>val2)
        return lcaInBST(root->left,val1,val2);
    else if(root->data<val1 && root->data<val2)
        return lcaInBST(root->right,val1,val2);
    return root->data;
}
