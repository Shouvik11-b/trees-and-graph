#include <bits/stdc++.h>

using namespace std;


//in this code we find the bridges in a graph 
//bridges are that two adjacent node which when cut form 2 different graph
void dfs(int parent,int vertex,vector<int> graph[],bool vis[],int intime[],int lowtime[],int &time){
    vis[vertex]=true;
    intime[vertex]=time;
    lowtime[vertex]=time;
    time++;
    for(auto child:graph[vertex]){
        if(child==parent)
        continue;

        if(vis[child]==false){
            dfs(vertex,child,graph,vis,intime,lowtime,time);
            lowtime[vertex]=min(lowtime[child],lowtime[vertex]);
            if(lowtime[child]>intime[vertex]){
                cout<<child<<" "<<vertex<<"\n";
            }
        }
        else{
            lowtime[vertex]=min(lowtime[child],lowtime[vertex]);
        }
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> graph[n+1];
    int m;//no of edges;
    cin>>m;

    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bool vis[n+1];
    int intime[n+1];
    int lowtime[n+1];
    for(int i=0;i<n+1;i++){
        intime[i]=0;
        lowtime[i]=0;
        vis[i]=false;
    }
int time=1;
    dfs(-1,1,graph,vis,intime,lowtime,time);

    
}