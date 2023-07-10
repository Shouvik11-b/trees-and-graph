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

bool childrensumproperty(node *root){
    if(root==NULL)
    return true;
    if(root->left==NULL && root->right==NULL)
    return true;

    int sum=0;
    if(root->left!=NULL)
    sum+=root->left->key;
    if(root->right!=NULL)
    sum+=root->right->key;


    return (sum==root->key && (childrensumproperty(root->left)&&childrensumproperty(root->right)));
}

int isbalanced(node *root){
    if(root==NULL){
        return 0;
    }
    int t1=isbalanced(root->left);
    if(t1==-1)
    return -1;
    int t2=isbalanced(root->right);
    if(t2== -1)
    return -1;

    if(abs(t1-t2)>1)
    return -1;
    else
    return max(t1,t2)+1;
}


int main(){

    node *root= new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left = new node(40);
    root->right->right = new node(50);
    root->right->right->left = new node(60);
    root->right->right->right = new node(70);

    if(childrensumproperty(root)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

    cout<<"\n";

    if(isbalanced(root)==-1)
    cout<<"NO";
    else
    cout<<"yes";

}