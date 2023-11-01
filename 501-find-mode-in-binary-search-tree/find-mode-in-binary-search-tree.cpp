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
    void f(TreeNode* root,vector<int>&v){
        if(!root) return ;
        f(root->left,v);
        v.push_back(root->val);
        f(root->right,v);
    }

    vector<int> findMode(TreeNode* root) {
       vector<int> v;
       f(root,v); 

        // sort(v.begin(),v.end());
       vector<int> ans;
       int x=v[0],c=1,mx=1;
        for(int i=1;i<v.size();i++){
            if(x!=v[i]){
                if(mx==c) ans.push_back(x);
                else if(mx<c){
                    ans.clear();
                    ans.push_back(x);
                    mx=c;
                }
                x=v[i];
                c=1;
            }
            else c++;
        }
        if(mx==c) ans.push_back(x);
        if(mx<c){
            ans.clear();
            ans.push_back(x);
            // mx=c;
        }

        if(v.size()==1) return v;
        return ans;
    }
};