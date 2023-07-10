#include<bits/stdc++.h>
using namespace std;

void createadj(vector<int> adj[],int v1,int v2){
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);

    return ;
}

void bfs(vector<int> adj[],int n,int s){
    bool vis[n+1];
    for(int i=0;i<n+1;i++){
        vis[i]=false;
    }
    queue<int> q;
    vis[s]=true;
    q.push(s);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto &child:adj[curr]){
            if(vis[child]){
                continue;
            }
            q.push(child);
            vis[child]=true;
        }
    }
return ;
}

void dfs(vector<int> adj[],bool vis[],int vertex){
    vis[vertex]=true;
    cout<<vertex<<" ";
    for(int child:adj[vertex]){
        if(vis[child]==true)
        continue;

        dfs(adj,vis,child);
    }

    return ;
}

void shortestdistancefromsource(vector<int> adj[],bool vis[],int source,int dist[]){
    queue<int> q;
    q.push(source);
    vis[source]=true;

    dist[source]=0;
    while(q.size()>0){
        int curr=q.front();
        q.pop();

        for(auto child:adj[curr]){
            if(vis[child])
            continue;

            q.push(child);
            dist[child]=dist[curr]+1;
            vis[child]=true;
        }
    }


}

int main(){
    int n;
    cin>>n;
    vector<int> adj[n+1];

   int t;
   cin>>t;
   for(int i=0;i<t;i++){
       int v1,v2;
       cin>>v1>>v2;
       createadj(adj,v1,v2);
   }

   bfs(adj,5,1);

  bool vis[n+1];
  memset(vis,0,sizeof(vis));

  int source=1;
  dfs(adj,vis,source);


}