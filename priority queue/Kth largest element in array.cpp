#include<queue>
#include<vector>
using namespace std;
int kthLargest (vector<int> arr, int n, int k){
    priority_queue<int,vector<int>,greater<int>> pq;		//MIN HEAP(SMALLEST ELEMENT ON TOP)
    vector<int> temp;
    for(int i=0; i<k; i++) {
        pq.push(arr[i]);
    }
    for(int i=k; i<n; i++) {
        if(pq.top() < arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    // while(!pq.empty()) {
    //     temp.push_back(pq.top());
    //     pq.pop();
    // }
    return pq.top();
}