#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> p;

vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    vector<int> ans;
	priority_queue<p,vector<p>,greater<p>> pq;
    for(int i=0; i<input.size(); i++) {
        vector<int> *temp = input[i];
        pq.push(make_pair(temp->at(0),make_pair(i,0)));
    }
    while(!pq.empty()) {
        pair<int,pair<int,int>> min = pq.top();
        pq.pop();
        ans.push_back(min.first);
        int arrayIndex = min.second.first;			//array from which min element is selected
        int elemIndex = min.second.second;			//index of the element within its array
        elemIndex++;								//moving to next index of the selected aray
        
        if(elemIndex < input[arrayIndex]->size())
            pq.push(make_pair(input[arrayIndex]->at(elemIndex),make_pair(arrayIndex,elemIndex)));
    }
    return ans;
}