/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    const int inf=-1e9+10;
    int sol(TreeNode *root,int &result){
        if(root==NULL){
            return inf;
        }
        
        int l=sol(root->left,result);
        int r=sol(root->right,result);
        
        result=max(l+root->val,result);
        result=max(r+root->val,result);
        result=max(result,l+r+root->val);
        result=max(result,root->val);
        int temp=max(l,r);
        temp=max(0,temp);
        return temp+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int result=INT_MIN;
        sol(root,result);
        
        return result;
    }
};