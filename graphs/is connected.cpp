/*Given an undirected graph G(V,E), check if the graph G is connected graph or not.

Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2 */

#include <iostream>
using namespace std;

void isConnected(int** edges, int n, int sv, bool* visited) {
    visited[sv] = true;
    for(int i=0; i<n; i++) {
        if(i==sv)
            continue;
        if(edges[sv][i] && !visited[i]) {
            visited[i] = true;
            isConnected(edges,n,i,visited);
        }
    }
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
    
    isConnected(edges,V,0,visited);
    int i;
    for(i=0; i<V; i++) {
        if(visited[i]==false)
            break;
    }
    if(i<V)
        cout<<boolalpha<<false;
    else
        cout<<boolalpha<<true;
    return 0;
}
