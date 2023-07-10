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

int getmin(node *root){
    if(root==NULL)
    return INT_MIN;

    return max(root->key,max(getmin(root->left),getmin(root->right)));
}

int maxlevel=0;
void printleftview(node *root,int level){
    if(root==NULL)
    return;

    if(maxlevel<level){
        cout<<root->key<<" ";
        maxlevel=level;
    }

    printleftview(root->left,level+1);
    printleftview(root->right,level+1);
}

int main(){
node *root= new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left = new node(40);
    root->right->right = new node(50);
    root->right->right->left = new node(60);
    root->right->right->right = new node(70);

cout<<getmin(root)<<" ";
printleftview(root,1);

}