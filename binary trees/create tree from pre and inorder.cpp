//Construct Tree from Preorder and Inorder
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/
int search(int *arr,int start,int end,int data){
    int i;
    for(i=start;i<=end;i++){
        if(arr[i] == data)
            return i;
    }
}

BinaryTreeNode<int>* buildTree(int *preorder, int *inorder, int inStart, int inEnd){
    static int preStart=0;
    if(inStart>inEnd)
        return NULL;
    BinaryTreeNode<int> *rootNode = new BinaryTreeNode<int>(preorder[preStart++]);
    int rootIndex = search(inorder,inStart,inEnd,rootNode->data);
    rootNode->left = buildTree(preorder, inorder, inStart, rootIndex-1);
    rootNode->right = buildTree(preorder, inorder, rootIndex+1, inEnd);
    return rootNode;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLenght, int *inorder, int inLength) {
    // Write your code here
	return buildTree(preorder, inorder, 0, inLength-1);
}
