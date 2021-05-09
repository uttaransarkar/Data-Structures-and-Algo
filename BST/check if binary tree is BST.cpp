#include<bits/stdc++.h>
class BSTCheck{
    public:
	bool bstcheck;
    int minimum;
    int maximum;
};

BSTCheck isBST1(BinaryTreeNode<int> *root){
    if(root == NULL){
        BSTCheck output;
    	output.bstcheck = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    BSTCheck leftCheck = isBST1(root->left);
    BSTCheck rightCheck = isBST1(root->right);
    int minimum = min(root->data,min(leftCheck.minimum,rightCheck.minimum));
    int maximum = max(root->data,max(leftCheck.maximum,rightCheck.maximum));
    bool finalcheck = (root->data>leftCheck.maximum) && (root->data < rightCheck.minimum) && leftCheck.bstcheck && rightCheck.bstcheck;
    BSTCheck finalOutput;
    finalOutput.bstcheck = finalcheck;
    finalOutput.minimum = minimum;
    finalOutput.maximum = maximum;
    return finalOutput;
}

bool isBST(BinaryTreeNode<int> *root){
       /* Don't write main().
	* Don't read input, it is passed as function argument.
	* Return output and don't print it.
	* Taking input and printing output is handled automatically.
	*/
    BSTCheck finalAns = isBST1(root);
    return finalAns.bstcheck;
}