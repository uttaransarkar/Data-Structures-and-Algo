/*Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void connectedComp(int** edges, int n, int sv, bool* visited, vector<int>& out) {
    if(!visited[sv]) {
        out.push_back(sv);
    	visited[sv] = true;
    }
    for(int i=0; i<n; i++) {
        if(i==sv)
            continue;
        if(edges[sv][i] && !visited[i]) {
            out.push_back(i);
            visited[i] = true;
            connectedComp(edges,n,i,visited,out);
        }
    }
}

int main()
{
  int V, E, tempX, tempY;
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
    bool* visited = new bool[V];
    for(int i=0; i<V; i++) {
        visited[i] = false;
    }
    
	vector<int> output;
    connectedComp(edges,V,0,visited,output);
    sort(output.begin(),output.end());
    for(int i=0; i<output.size(); i++) {
        cout<<output[i]<<" ";
    }
    
    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            vector<int> temp;
            connectedComp(edges,V,i,visited,temp);
            sort(temp.begin(),temp.end());
            cout<<endl;
            for(int i=0; i<temp.size(); i++) {
        		cout<<temp[i]<<" ";
    		}
        }
    }
  	return 0;
}