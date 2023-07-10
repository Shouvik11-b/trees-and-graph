#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    node *left,*right;
    node(int x){
     key=x;
     left=NULL;
     right=NULL;
    }
};

node *newnode(int x){
    node *root=new node(x);

    return root;
}

node *bstinsert(int x,node *root){
    if(root==NULL){
        return newnode(x);
    }

    if(root->key<x)
    root->right=bstinsert(x,root->right);
    else if(root->key>x)
    root->left=bstinsert(x,root->left);

    return root;
}

//iterative approach to insert in a bst;
node *insert(int x,node *root){
    node *temp= new node(x);
    node *parent=root;
    node *curr=root;
    while(curr!=NULL){
        parent=curr;
        if(curr->key>x){
            curr=curr->left;
        }
        else if(curr->key<x){
            curr=curr->right;
        }
        else{
            return root;
        }
    }
    if(root==NULL)
    return temp;

    if(parent->key>x){
        parent->left=temp;
    }
    else{
      parent->right=temp;
    }

    return root;
}


node *getsuccesor(node *root){
    node *curr=root->right;
    while(curr->left!=NULL && curr!=NULL){
        curr=curr->left;
    }

    return curr;

}

node *delnode(int x,node *root){
    if(root==NULL)
    return root;

    if(root->key<x){
        root->right=delnode(x,root->right);
    }
    else if(root->key>x){
        root->left=delnode(x,root->left);
    }
    else{
        if(root->left==NULL){
            node *temp=NULL;
            temp=root->right;
            delete(root);
            return temp;
        }
        else if(root->right==NULL){
            node *temp=NULL;
            temp=root->left;
            delete(root);
            return temp;
        }
        else{
            node *succ=getsuccesor(root);
            root->key=succ->key;
            delnode(succ->key,root->right);
        }
    }

    return root;
}

void inorder(node *root){
    if(root==NULL)
    return ;

    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
    return ;
}

int main(){

node *root=NULL;

    root=insert(10,root);
    root=insert(20,root);
    root=insert(11,root);
    root=insert(5,root);
    root=insert(30,root);
    root=insert(40,root);
    root=insert(35,root);

    root=delnode(30,root);

    inorder(root);

    

    return 0;
    
}