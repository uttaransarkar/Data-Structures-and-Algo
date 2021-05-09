#include<bits/stdc++.h> 
PairAns minMax(BinaryTreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	if(root == NULL){
        PairAns p;
        p.min = INT_MAX;
        p.max = 0;
        return p;
    }
    PairAns leftAns = minMax(root->left);
    PairAns rightAns = minMax(root->right);
    PairAns p;
    p.max = max(root->data,max(leftAns.max, rightAns.max));
    p.min = min(root->data,min(leftAns.min, rightAns.min));
    return p;
}