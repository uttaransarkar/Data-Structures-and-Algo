/* Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1. Return true if given binary tree is balanced, 
false otherwise. */

class Pair{
    public:
    int height;
    bool isBal;
};

Pair isBalancedHelper(BinaryTreeNode<int> *root){
    if(root == NULL){
        Pair p;
        p.height = 0;
        p.isBal = true;
        return p;
    }
    Pair leftAns = isBalancedHelper(root->left);
    Pair rightAns = isBalancedHelper(root->right);

    if(!(leftAns.isBal||rightAns.isBal)){
        Pair p;
        p.isBal = false;
        p.height = max(leftAns.height, rightAns.height)+1;
        return p;
    }
    Pair p;
    if(abs(leftAns.height-rightAns.height)<=1 && leftAns.isBal && rightAns.isBal)
        p.isBal = true;
    else
        p.isBal = false;
    p.height = max(leftAns.height, rightAns.height)+1;
    return p;
}

bool isBalanced(BinaryTreeNode<int> *root) {
    // Write your code here
	Pair ans = isBalancedHelper(root);
    return ans.isBal;
}
