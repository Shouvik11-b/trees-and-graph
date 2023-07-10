#include <bits/stdc++.h>
using namespace std;

void aritculation(vector<int> adj[],int &time,int s,vector<int> &points,vector<int> &in,vector<int> &low,int prev){
    time++;
     in[s]=time;
     low[s]=time;
     for(auto child:adj[s]){
        if(child==prev){
            continue;
        }
        if(in[child]==-1){
            aritculation(adj,time,child,points,in,low,s);
            low[s]=min(low[child],low[s]);
            if(low[child]>=in[s]){
                points.push_back(s);
            }
        }
        else{
            low[s]=min(low[child],low[s]);
        }
     }
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> adj[n+1];
    for(int i=0;i<n;i++){
        int v,u;
        cin>>v>>u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }


}