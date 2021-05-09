#include <queue>
#include <vector>
vector<int> kSmallest(int *input, int n, int k) {
    priority_queue<int> pq;         //MAX HEAP(LARGEST ELEMENT ON TOP)
    vector<int> ans;
	for(int i=0;i<k;i++) {
        pq.push(input[i]);			//consider first k elements as solution initially
    }
    for(int i=k;i<n;i++) {
        if(pq.top() > input[i]) {	//compare the initial PQ with remaining (n-k) elements and according replace
            pq.pop();
            pq.push(input[i]);
        }
    }
    while(!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}