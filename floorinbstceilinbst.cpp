#include <bits/stdc++.h> 
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

int floor(node *root,int x){
    if(root==NULL)
    return -1;
    int ans=-1;
    
   if(root->key <=x){
        ans = root->key;
    }
    //cout<<ans<<" ";
    if(root->key > x){
        ans=max(ans,floor(root->left,x));
    }
    else{
        ans=max(ans,floor(root->right ,x));
    }

    return ans;
}

int floorusingiteration(node *root,int x){
    if(root==NULL)
    return -1;
int res=-1;
    while(root1=NULL){
        if(root->key==x){
            res=x;
            return x;
        }
        else if(root->key>x){
            root=root->left;
        }
        else{
            res=root-key;
            root=root->right;
            
        }
    }

    return res;
}

int ceilusingiteration(node *root,int x){
    if(root==NULL)
    return -1;

    int res=-1;
    while(root!=NULL){
        if(root->key==x){
            return x;
        }
        else if(root->key<x){
            root=root->right;
        }
        else{
            res=root->key;
            root=root->left;
        }
    }

    return res;
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

    int res=floor(root,2);

    cout<<res;

    return 0;
    
}