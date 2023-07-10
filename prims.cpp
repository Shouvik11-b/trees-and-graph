#include <bits/stdc++.h>
using namespace std;

//here we have to fing min spanning tree;we use 3 array here parent,key and mst
//the parent array store the parent of each node the key array is initialised to inf ,mst array to false;
//here we have to iterate over the key array and find the min key initially key of index0 is 0
//the we have to check if the min key is not already visited then we take into consideration of that index
//then 
int main(){
int N,m;//N= nodes,m=edges;
cin>>N>>m;
int inf=1e5;
vector<pair<int,int>> adj[N];
for(int i=0;i<m;i++){
    int a,b,wt;
    cin>>a>>b>>wt;

    adj[a].push_back({b,wt});
    adj[b].push_back({a,wt});
}

int key[N],parent[N];
bool mst[N];

for(int i=0;i<N;i++)
key[i]=inf,parent[i]=-1,mst[i]=false;

key[0]=0,parent[0]=0;

for(int cnt=0;cnt<N;cnt++){
    int mn=inf,j=-1;
    for(int i=0;i<N;i++)
    if(key[i]<mn && mst[i]==false)
    mn=key[i],j=i;

    mst[j]=true;

    for(auto child:adj[j]){

        if(key[child.first]>child.second){
            key[child.first]=child.second;
            parent[child.first]=j;
        }

    }

}
    


}

//we can also implement this using priority queue where the key with least value is always at top;
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<pair<int,int>> adj[A+1];
    int m=B.size();
    for(int i=0;i<m;i++){
        adj[B[i][0]].push_back({B[i][1],B[i][2]});
        adj[B[i][1]].push_back({B[i][0],B[i][2]});
    }
    int inf=INT_MAX;
    int ms[A+1],key[A+1];
    for(int i=0;i<A+1;i++){
        ms[i]=-1;
        key[i]=inf;
    }
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> gq;
    key[1]=0;
    //ms[1]=1;
    gq.push({0,1});
    while(gq.empty()==false){
        
        
        int u=gq.top().second;
        gq.pop();
        ms[u]=1;
        for(auto child:adj[u]){
            if(ms[child.first]==-1 && key[child.first]>child.second){
                key[child.first]=child.second;
                gq.push({key[child.first],child.first});
                
            }
        }
    }

    int cost=0;
    for(int i=1;i<A+1;i++){
        //cout<<key[i]<<" ";
        cost+=key[i];
    }

    return cost;
}