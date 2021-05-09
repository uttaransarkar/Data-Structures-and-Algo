/*Code : Prim's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -

1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.

Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getMinVertex(int *weight, int n, bool *visited) {
    int minVertex = -1;
    for(int i=0; i<n; i++) {
        if(!visited[i] && ((minVertex==-1)||(weight[minVertex]>weight[i])))
            minVertex = i;
    }
    return minVertex;
}

void prims(int** edges, int n) {
    bool *visited = new bool[n];
    int *weight = new int[n];
    int *parent = new int[n];
    
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        weight[i]=INT_MAX;
    }
    weight[0] = 0;
    parent[0] = -1;
    for(int i=0; i<n; i++) {
        int currVertex = getMinVertex(weight,n,visited);
        visited[currVertex] = true;
        for(int j=0; j<n; j++) {
            if(edges[currVertex][j]!=0) {
                if(weight[j] > edges[currVertex][j] && !visited[j]) {
                    weight[j] = edges[currVertex][j];
                    parent[j] = currVertex;
                }
            }
        }
    }
    for(int i=1; i<n; i++) {
        cout<<min(i,parent[i])<<" "<<max(i,parent[i])<<" "<<weight[i]<<endl;
    }
    delete [] parent;
    delete [] weight;
    delete [] visited;
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    int** edges=new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            edges[i][j]=0;
        }
    }
    for(int i=0;i<E;i++)
    {
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s]=w;
        edges[s][f]=w;
    }
    prims(edges,V);
  	return 0;
}