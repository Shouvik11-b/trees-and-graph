/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int ct(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        
        int ans=0;
        ans+=ct(root->left);
        ans+=ct(root->right);
        return ans+1;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int> v;
        queue<TreeNode *> q;
        if(root==NULL){
            string res="#";
            return res;
        }
        q.push(root);
        v.push_back(root->val);
        string str;
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL)
            {
                str.append("#,");
            }
            else
            {
                str.append(to_string(curr->val)+',');
            }
           if(curr!=NULL)
           {
               q.push(curr->left);
               q.push(curr->right);
           }
        }
            
        
        
        
        
        
        //cout<<s<<" ";
        return str;
    }
    TreeNode* sol(int i,vector<int> &v){
        int n=v.size();
        if(i>=n)
            return NULL;
        if(v[i]==-10000)
            return NULL;
        TreeNode *root=new TreeNode(v[i]);
        //root->val=v[i];
        root->left=sol(2*i+1,v);
        root->right=sol(2*(i+1),v);
        
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        vector<int> v;
        //cout<<s<<" ";
        int n=s.size();
        //cout<<" "<<n<<" ";
        for(int i=0;i<n;i++){
            if(s[i]==',')
                continue;
            if(s[i]=='#'){
                v.push_back(-10000);
            }
            else{
                string res;
        while(i<n && s[i]!=','){
            res+=s[i];
            i++;
               }
                v.push_back(stoi(res));
            }
        }
        TreeNode *root=new TreeNode(v[0]);
        queue<TreeNode *> q;
        q.push(root);
        if(v[0]==-10000){
            return NULL;
        }
        int z=v.size(),i=1;
        while(!q.empty() && i<z){
            auto curr=q.front();
            q.pop();
            if(v[i]!=-10000){
                TreeNode *temp=new TreeNode(v[i]);
                q.push(temp);
                curr->left=temp;
            }
            else{
                curr->left=NULL;
            }
            if(i+1<z && v[i+1]!=-10000){
                TreeNode *temp=new TreeNode(v[i+1]);
                q.push(temp);
                curr->right=temp;
            }
            else{
                curr->right=NULL;
            }
            i=i+2;
        }
        
        return root;
    }
};