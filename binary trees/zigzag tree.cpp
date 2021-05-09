/* Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should 
get printed from left to right and even level right to left. */

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root==NULL)
        return;
	stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    bool order=true;
    while(!s1.empty()){
        BinaryTreeNode<int> *curr = s1.top();
        s1.pop();
        if(curr){
            cout<<curr->data<<" ";
            if(order){
            	if(curr->left)
            		s2.push(curr->left);
        		if(curr->right)
            		s2.push(curr->right);
            } else {
                if(curr->right)
            		s2.push(curr->right);
                if(curr->left)
            		s2.push(curr->left);
            }
        }
        if(s1.empty()){
            cout<<endl;
            s1.swap(s2);
            order = !order;
        }
    }
}
