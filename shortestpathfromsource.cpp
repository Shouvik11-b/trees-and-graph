#include <bits/stdc++.h>
using namespace std;

void shortestpathusingtopologicalsorting(vector<pair<int,int>> graph[],int dist[],int nfactor[],int n){
queue<int> q;
for(int i=1;i<=n;i++){
    if(nfactor[i]==0){
    q.push(i);
    dist[i]=0;
    }
}

while(q.size()>0){
    int curr=q.front();
    q.pop();
    for(auto child:graph[curr]){
        dist[child.first]=min(child.second+dist[curr],dist[child.first]);
        //cout<<child.first<<" "<<child.second<<"\n";
    nfactor[child.first]--;
    if(nfactor[child.first]==0)
    q.push(child.first);
    }
}

}

int main(){
    int n;//no of vertexs
    cin>>n;
    int m;
    cin>>m;//no of edges;
    vector<pair<int,int>> graph[n+1];//pair is taken to take weight of the edge;
    int nfactor[n+1];
    memset(nfactor,0,sizeof(nfactor));
    for(int i=0;i<m;i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back({v2,wt});
        nfactor[v2]++;
    }

     int dist[n+1];
     int maxdist=1e5+10;
     for(int i=0;i<n+1;i++){
         dist[i]=maxdist;
     }

     

     shortestpathusingtopologicalsorting(graph,dist,nfactor,n);

     for(int i=1;i<=n;i++)
     cout<<dist[i]<<" ";

}