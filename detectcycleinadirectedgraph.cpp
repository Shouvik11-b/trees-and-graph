#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[],int vertex,bool vis[],bool loop[]){
    vis[vertex]=true;
    loop[vertex]=true;

    for(int child:adj[vertex]){
        if(vis[child]==false && dfs(adj,child,vis,loop)){
            return true;
        }
        else if(loop[child]==true){
            return true;
        }
    }
     loop[vertex]=false;
    return false;

}

int main(){
    int n;
    cin>>n;

    vector<int> adj[n+1];

    for(int i=0;i<n;i++){
        int v1,v2;
        cin>>v1>>v2;

        graph[v1].push_back(v2);
    }

    bool vis[n+1];
    bool loop[n+1];

    memset(vis,0,sizeof(vis));
    memset(loop,0,sizeof(loop));
bool ans=false;
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
        ans= (ans|dfs(adj[],i,vis,loop));
        }
    }

    
}