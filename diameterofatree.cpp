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

int mx=0;

int diameteroftree(node *root){
    if(root==NULL)
    return 0;

    int height1=diameteroftree(root->left);
    int height2=diameteroftree(root->right);

    mx=max(mx,height1+height2+1);

    return max(height1,height2)+1;
}

int main(){

node *root= new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left = new node(40);
    root->right->right = new node(50);
    root->right->right->left = new node(60);
    root->right->right->right = new node(70);

int res=diameteroftree(root);

cout<<mx;

    return 0;
}