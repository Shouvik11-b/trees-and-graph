 #include <bits/stdc++.h>

 using namespace std;

 void dijkstra(int source,int dist[],vector<pair<int,int>> graph[]){
    set<pair<int,int>> s;
    s.insert({0,source});
dist[source]=0;
    while(s.empty()==false){
        auto curr=*s.begin();
        s.erase(s.begin());
        if(curr.first>dist[curr.second])
            continue;
        for(auto child:graph[curr.second]){
            if(dist[child.first]>curr.first+child.second){
                dist[child.first]=curr.first+child.second;
                s.insert({dist[child.first],child.first});
            }
        }
    }
 }

 int main(){
     int n;
     cin>>n;
     
     vector<pair<int,int>> graph[n+1];

     int m;//no of edges;
     cin>>m;

     for(int i=0;i<m;i++){
         int v1,v2,wt;
         cin>>v1>>v2>>wt;

         graph[v1].push_back({v2,wt});
         graph[v2].push_back({v1,wt});
     }
     int dist[n+1];
     int inf=1e6+10;

     for(int i=0;i<n+1;i++){
         dist[i]=inf;
     }

     dist[1]=0;

     dijkstra(1,dist,graph);

for(int i=1;i<=n;i++)
cout<<dist[i]<<" ";

 }
