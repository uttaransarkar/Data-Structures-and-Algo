/*Code : Get Path - DFS
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.*/

#include <iostream>
#include <vector>
using namespace std;

vector <int> getPath(int** edges, int n, int sv, int ev, bool* visited) {
    visited[sv] = true;
    if(sv == ev) {
        vector<int> out;
        out.push_back(ev);
        return out;
    }
    vector<int> output;
    for(int i=0; i<n; i++) {
        if(i == sv)
            continue;
        if (edges[sv][i] && !visited[i]){
            output = getPath(edges,n,i,ev,visited);
            if(!output.empty()) {
                output.push_back(sv);
                return output;
            }
        }
    }
    return output;
}

int main() {
    int V, E;
    cin >> V >> E;
    
	int **edges=new int*[V];
  	for(int i=0;i<V;i++){
    	edges[i]=new int[V];
    	for(int j=0;j<V;j++)
      		edges[i][j]=0;
  	}

  	for(int i=0;i<E;i++){
    	int a,b;
    	cin>>a>>b;
    	edges[a][b]=1;
    	edges[b][a]=1;
  	}

  	int v1,v2;
  	cin>>v1>>v2;
    
    bool* visited = new bool[V];
    for(int i=0; i<V; i++) {
        visited[i] = false;
    }

    vector<int> ans = getPath(edges,V,v1,v2,visited);
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
  	return 0;
}
