#include <bits/stdc++.h>
using namespace std;

//here we are given weight and the two vertex of an edges
//first we have to sort the edges on basis of their weight 
//then we have to iterate through the sorted list of edges
//we have to check if both the nodes belong to the same component 
// if they dont belong to the same component then we have to add that edge else reject that edge

struct node{
    int wt,u,w;

    node(int x,int y,int z){
        wt=x;
        u=y;
        w=z;
    }
};

bool comp(node a,node b){
    return a.v<b.v;
}

int findparent(int x,int parent[]){
    if(x==parent[x])
    return x;

    return findparent(parent[x],parent);
}

void unin(int x,int y,int parent[],int ran[]){
    int a=findparent(x,parent);
    int b=findparent(y,parent);

    if(ran[a]>ran[b]){
        parent[b]=a;
    }
    else{
        parent[a]=b;
        if(ran[a]==ran[b])
        ran[b]++;

    }
}

int main(){
    int n;
    cin>>n;

    int m;
    cin>>m;

    vector<pair<int,int>> ans;
    vector<node> graph;
    for(int i=0;i<m;i++){
        int wt,v1,v2;
        cin>>wt>>v1>>v2;

        graph.push_back(node(wt,v1,v2));
    }

    int parent[n+1];
    int ran[n+1];
    for(int i=0;i<=n;i++){
        parent[i]=i;
        ran[i]=0;
    }

    sort(graph.begin(),graph.end(),comp);
int cost=0;
    for(int i=0;i<m;i++){
        if(findparent(graph[i].u,parent)!=findparent(graph[i].w,parent){
            unin(graph[i].u,graph[i].w,parent,ran);
            cost+=graph[i].wt;
            ans.push_back(graph[i].u,graph[i].w);
        }
    }

    cout<<cost<<"\n";
}