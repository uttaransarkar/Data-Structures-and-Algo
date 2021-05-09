BinaryTreeNode<int>* constructTree(int *input, int start, int end) {
	if(start>end)
        return NULL;
    int mid = (start+end)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    root->left = constructTree(input,start,mid-1);
    root->right = constructTree(input,mid+1,end);
    return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	return constructTree(input,0,n-1);
}