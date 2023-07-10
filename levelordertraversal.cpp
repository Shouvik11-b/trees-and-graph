#include <bits/stdc++.h>
using namespace std;

struct node{
int key;
node *left,*right;

node(int k){
    key=k;
    left=right=NULL;
}
};

void levelordertraversal(node *root){
    if(root==NULL)
    return;

    queue<node *> q;
    q.push(root);
    while(q.empty()==false){
        node *curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left!=NULL)
        q.push(curr->left);
        if(curr->right!=NULL)
        q.push(curr->right);

    }

}

void levelordertraversallinebyline(node *root){
    if(root==NULL)
    return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        node *curr = q.front();
        q.pop();
        if(curr==NULL){
            cout<<"\n";
            q.push(NULL);
        }
        else{
            cout<<curr->key<<" ";
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);
        }
    }
}

void levelordertraversallinebylinemethod2(node *root){
    if(root==NULL)
    return;

    queue<node *> q;
    q.push(root);
    while(q.empty()==false){
        int cnt=q.size();
        for(int i=0;i<cnt;i++){
            node *curr = q.front();
            q.pop();
            if(curr->left !=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);

            cout<<curr->key<<" ";
        }
        cout<<"\n";
    }
}

void spiraltraversaloftree(node *root){
    stack<node *> s1,s2;
    s1.push(root);
    
    bool r=false;
    while(s1.size()>0 || s2.size()>0){
        if(r){

           int cnt=s2.size();
        for(int i=0;i<cnt;i++){
            node *curr=s2.top();
            s2.pop();
            cout<<curr->key<<" ";
            if(curr->left!=NULL)
            s1.push(curr->left);
            if(curr->right!=NULL)
            s1.push(curr->right);

        } 
 
        }
        else{
        int cnt=s1.size();
        for(int i=0;i<cnt;i++){
            node *curr=s1.top();
            s1.pop();
            cout<<curr->key<<" ";
            if(curr->left!=NULL)
            s2.push(curr->left);
            if(curr->right!=NULL)
            s2.push(curr->right);

        }

        }
        cout<<"\n";
        r=!r;
        
    }
}

int findmaxwidth(node *root){
    if(root==NULL)
    return 0;

    queue<node *> q;
    q.push(root);

    int mx=0;
    while(q.empty()==false){
        int z=q.size();
        mx=max(z,mx);
        for(int i=0;i<z;i++){
            node *curr = q.front();
            q.pop();
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);


        }
    }

    return mx;
}



int main(){

    node *root= new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left = new node(40);
    root->right->right = new node(50);
    root->right->right->left = new node(60);
    root->right->right->right = new node(70);


   spiraltraversaloftree(root);
   cout<<"\n";
   cout<<findmaxwidth(root);

    return 0;
}