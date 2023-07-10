#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;// no of nodes in graph
    cin>>n;

    vector<pair<int,int>> adj[n+1];
    int m;//no of edges in graph
    cin>>m;

    for(int i=0;i<m;i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;

        adj[v1].push_back({v2,wt});
        adj[v2].push_back({v1,wt});
    }

    int key[n+1];
    //key[1]=0;
    int z=1e6+10;
    for(int i=0;i<=n;i++){
        key[i]=z;
    }
    key[1]=0;
    bool vis[n+1];
    for(int i=0;i<=n;i++)
    vis[i]=false;

    int parent[n+1];
    parent[1]=1;
     int mn=1,k=n;
    while(k){
        //cout<<"r";
        int mm=z;
        for(int i=1;i<=n;i++){
            if(vis[i]==false && key[i]<mm){
                mn=i;
                mm=key[i];
                //cout<<mn<<" ";
            }
        }
        //cout<<mn<<" ";
        vis[mn]=true;
        for(auto child:adj[mn]){
            if(vis[child.first]==false && child.second<key[child.first]){
                key[child.first]=child.second;
                parent[child.first]=mn;
                //cout<<child.first<<" "<<mn<<" "<<child.second<<"\n";
            }
            
        }
        
        
        k--;
    }

    for(int i=1;i<=n;i++)
    cout<<parent[i]<<" ";
}

sol(){
    key[]
    ms[];
    gq;
    while(gq.empty()){
        curr =pq.top();
        curr.pop()
        
    }
}