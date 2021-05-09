/* Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list. */

#include <queue>
vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
	queue<BinaryTreeNode<int>*> pendingNodes;
    node<int> *head=NULL, *tail=NULL;
    vector<node<int>*> output;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int> *front = pendingNodes.front();
        if(front) {
            node<int> *newNode = new node<int>(front->data);
            pendingNodes.pop();
            if(front->left)
            	pendingNodes.push(front->left);
        	if(front->right)
            	pendingNodes.push(front->right);
            if(head==NULL){
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }    
        }
        else{
            output.push_back(head);
            head = NULL;
            tail = NULL;
            pendingNodes.pop();
            if(pendingNodes.size()==0)
                break;
            pendingNodes.push(NULL);
        }
    }
    return output;
}