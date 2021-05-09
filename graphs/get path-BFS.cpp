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
