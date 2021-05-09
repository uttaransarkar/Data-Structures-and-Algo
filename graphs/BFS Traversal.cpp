/*Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note : 1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'. */

#include <iostream>
#include <queue>
using namespace std;

void print(int **edges, int n, int sv, bool* visited) {  
    queue<int> pendingVert;
    pendingVert.push(sv);
    visited[sv] = true;
    while(!pendingVert.empty()) {
        int curr = pendingVert.front();
        pendingVert.pop();
        cout<<curr<<" ";
        for(int i=0; i<n; i++) {
            if(i==curr)
                continue;
            if(edges[curr][i]==1 && !visited[i]) {
                pendingVert.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int **edges, int n) {
    bool* visited = new bool[n];        //keep track of vertices visited, so that they are not considered twice
    for(int i=0; i<n; i++) {
        visited[i] = false;
    }
    print(edges,n,0,visited);
    for(int i=0; i<n; i++) {
        if(!visited[i])
            print(edges,n,i,visited);
    }
    delete [] visited;
}

int main() {
    int V, E;
    cin >> V >> E;
    
    int** edges = new int*[V];      //adjacency matrix
    for(int i=0; i<V; i++) {
        edges[i] = new int[V];
        for(int j=0; j<V; j++) {	//vertices
            edges[i][j] = 0;
        }
    }
    
    for(int i=0; i<E; i++) {		//edges
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    BFS(edges,V);
  return 0;
}
