/*Code : Kruskal's Algorithm
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
1 2 1
0 1 3
0 3 5
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
    public:
    int source;
    int dest;
    int  weight;
    
    Edge(){
        weight = 0;
        source = 0;
        dest = 0;
    }
    
    Edge(int w,int s,int d){
        weight = w;
    	source = s;
    	dest = d;        
    }
};

bool compareEdge(Edge e1, Edge e2) { 
    return e1.weight < e2.weight; 
} 

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    Edge *input = new Edge[E];
    for(int i=0;i<E;i++){
        int s,d,w;
        cin>>s>>d>>w;   
        input[i].weight = w;
        input[i].source = s;
        input[i].dest = d;
    }
    sort(input,input+E,compareEdge);
    vector<Edge> output;
    int *parent = new int[V];
    for(int i=0; i<V; i++) {
        parent[i] = i;
    }
    
    int count = 0,i=0;
    while(count!=V-1) {
        Edge curr = input[i];
        int p1 = parent[curr.source];
        while(p1 != parent[p1])
            p1 = parent[p1];
        int p2 = parent[curr.dest];
        while(p2 != parent[p2])
            p2 = parent[p2];
        if(p1 != p2) {
            output.push_back(curr);
            count++;
            parent[p1] = p2;
        }
        i++;
    }
    
    for(int i=0; i<output.size(); i++) {
        cout<<min(output[i].source,output[i].dest)<<" "<<max(output[i].source,output[i].dest)<<" "<<output[i].weight<<endl;
    }
    
  return 0;
}