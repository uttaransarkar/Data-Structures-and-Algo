#include <stack>

void reverseStack(stack<int> &input, stack<int> &extra) {
	// Write your code here
	if(input.size()==1){
        return;
    }
    int n = input.top();
    input.pop();
    reverseStack(input,extra);
    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }
    input.push(n);
    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
}

#include <queue> 
void reverseQueue(queue<int> &q) { 
    if(q.size() <= 1) { 
        return; 
    } 
    int front = q.front(); 
    q.pop(); 
    reverse Queue(q); 
    q.push(front); 
}