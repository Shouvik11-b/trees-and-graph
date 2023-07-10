#include <bits/stdc++.h>
using namespace std;

//topological sorting is printing number according to their order 
// that is print all parent element first
//if graph has cycle then it cannot print all elements
void topologicalsorting(vector<int> graph[],int nfactor[],int n){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(nfactor[i]==0){
            q.push(i);
        }
    }

    while(q.size()>0){
        int curr=q.front();
        q.pop();
        for(int child:graph[curr]){
            nfactor[child]--;
            if(nfactor[child]==0){
                q.push(child);
            }
            
        }
        cout<<curr<<" ";
    }

    return;

}

//shortest path from source to any vertex of weighted graph can also be found using 
//kahns algorithm
//here we have to declare a distance array before hand and for each visit of a node update it to 
// the minimum value;
void shortestpathfromsource(vector<pair<int,int>> graph2[],int nfactor[],int n,int dist[],int source){
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
        for(int child:graph[curr]){
            nfactor[child]--;
            dist[child]=min(dist[curr]+child.second,dist[child]);
            if(nfactor[child]==0){
                q.push(child.first);
            }
            
        }
        
    }

    return;
}


//if graph has cycle it will have less count than total node;
bool checkifgraphhascycle(vector<int> graph[],int nfactor[],int n){   
queue<int> q;
    for(int i=1;i<=n;i++){
        if(nfactor[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    while(q.size()>0){
        int curr=q.front();
        q.pop();
        for(int child:graph[curr]){
            nfactor[child]--;
            if(nfactor[child]==0){
                q.push(child);
            }
            
        }
        cnt++;
    }
    //cout<<cnt;
    return cnt!=n;
    }

   

    //topological sorting using dfs 
    //here a stack is used and the elements which will come at last are stored fast;
    stack<int> s;
    void dfssort(vector<int> graph[],int source,int vis[]){
       vis[source]=1;
       for(auto child:graph[source]){
           if(vis[child]==1)
           continue;

           dfssort(graph,child,vis);
       }
       s.push(source);

       return ;
    }

int main(){
    int n;
    cin>>n;

    vector<int> graph[n+1];

    int m;//no of edges;
    cin>>m;
     int nfactor[n+1];
     memset(nfactor,0,sizeof(nfactor));
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;//directed toward v2 from v1;
        graph[v1].push_back(v2);
        nfactor[v2]++;
    }

    //topologicalsorting(graph,nfactor,n);

    //if(detectcycleingraph(graph,nfactor,n) == true){
    //    cout<<"YES"<<"\n";
    //}
    //else{
    //    cout<<"NO"<<"\n";
   // }

   //for using toposort in dfs
    int vis[n+1];
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(nfactor[i]==0){
            dfssort(graph,i,vis);
        }
    }

    while(s.size()>0){
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return 0;
}