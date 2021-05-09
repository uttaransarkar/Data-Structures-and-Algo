#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getMinVertex(int* distance, int n, bool* visited) {
    int minVert = -1;
	for(int i=0; i<n; i++) {
        if(!visited[i] && (minVert==-1 || distance[minVert]>distance[i]))
            minVert = i;
    }
    return minVert;
}

void djikstra(int** edges, int n) {
    bool *visited = new bool[n];
    int *distance = new int[n];
    
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    distance[0] = 0;
    for(int i=0; i<n; i++) {
        int minVertex = getMinVertex(distance,n,visited);
        visited[minVertex] = true;
        for(int j=0; j<n; j++) {
            if(edges[minVertex][j]!=0) {
                if(!visited[j] && distance[j] > distance[minVertex]+edges[minVertex][j])
                    distance[j] = distance[minVertex]+edges[minVertex][j];
            }
        }
    }
    for(int i=0; i<n; i++) {
        cout<<i<<" "<<distance[i]<<endl;
    }
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
    djikstra(edges,V);
  	return 0;
}