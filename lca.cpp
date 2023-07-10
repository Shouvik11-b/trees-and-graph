#include<bits/stdc++.h>
using namespace std;

struct node{
int key;
node *left,*right;

node(int k){
    key=k;
    left=right=NULL;
}
};

node *lca(node *root,int n1,int n2){
    if(root==NULL)
    return NULL;

    if(root->key==n1 || root->key==n2)
    return root;

    node *l1=lca(node->left);
    node *l2=lca(node->right);

    if(l1!=NULL && l2!=NULL)
    return root;

    if(l1!=NULL)
    return l1;
    else 
    return l2;
}

//finding least common ancestor in naive approach
bool findpath(node *root,vector<node *> v,int n)
{
    if(root ==NULL)
    return false;

    

    v.pb(root);

   if(root->key==n)
   return true;

    bool res=findpath(root->left,v,n);
    if(res==true){
        return true;
    }
    else{
        v.pop_back();
    }
}



int main(){
    node *root= new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left = new node(40);
    root->right->right = new node(50);
    root->right->right->left = new node(60);
    root->right->right->right = new node(70);



    
}