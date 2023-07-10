 #include <bits/stdc++.h>

 using namespace std;

const int r=1000;
int parent[r],ran[r];
//int rank[r];

int findparent(int x){
    if(x==parent[x])
    return x;

    

    return findparent(parent[x]);
}

void unin(int x,int y){
    //find the number whose parent has a greater rank and then add other number to 
    // the that number

    int a1=findparent(x);
    int a2=findparent(y);

    if(ran[a1]>ran[a2]){
      parent[a2]=a1;
    }
    else{
        //cout<<"r"<<"\n";
        if(ran[a1]==ran[a2]){
            ran[a2]++;
        }
        parent[a1]=a2;
    }

    return;
}

int main(){
    int n;
    cin>>n;

    
    for(int i=0;i<=n;i++){
        parent[i]=i;
        ran[i]=0;
    }

    int m;//the number of union to be done;
cin>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;

        unin(v1,v2);
    }

    for(int i=1;i<=n;i++){
        cout<<parent[i]<<" ";
    }
}