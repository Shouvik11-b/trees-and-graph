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

void inorder(node *root){
    if(root==NULL)
    return ;

    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

void preorder(node *root){
    if(root==NULL)
    return ;

    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node *root){
    if(root==NULL)
    return ;

    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";
}

int height(node *root){
    if(root==NULL)
    return 0;

    int sum = max(height(root->left),height(root->right))+1;
    
    return sum;
}

void printnodeatheightk(node *root,int k){
    if(root==NULL)
    return ;
    if(k==0){
        cout<<root->key<<" ";
        return;
    }

    printnodeatheightk(root->left,k-1);
    printnodeatheightk(root->right,k-1);
    
}



node *prev=NULL;
node * binarytreetodoublylinkedlist(node *root){
if(root==NULL)
return root;
node *head=binarytreetodoublylinkedlist(root->left);
if(prev==NULL){
    head=root;
}
else{
    prev->right=root;
    root->left=prev;
}
prev=root;
binarytreetodoublylinkedlist(root->right);

return head;
}

int main(){

    node *root= new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left = new node(40);
    root->right->right = new node(50);
    root->right->right->left = new node(60);
    root->right->right->right = new node(70);

    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<height(root);
    cout<<endl;
    printnodeatheightk(root,2);
    cout<<endl;
    levelordertraversal(root);


return 0;
}