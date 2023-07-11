/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void f(TreeNode* root,TreeNode* p,map<TreeNode* ,TreeNode* > &m){
        if(!root) return ;

        m[root]=p;
        f(root->left,root,m);
        f(root->right,root,m);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode* , TreeNode*> m;
        f(root,NULL,m);

        vector<int> vis(m.size()+100,0);
        queue<pair<TreeNode*,int>> q;
        q.push({target,k});
        vis[target->val]=1;

        vector<int> ans;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* t=it.first;
            int x=it.second;

            if(it.second==0){
                ans.push_back(it.first->val);
                continue;
            }
            if(t->left && !vis[t->left->val]){
                vis[t->left->val]=1;
                q.push({t->left,x-1});
            }

            if(t->right && !vis[t->right->val]){
                vis[t->right->val]=1;
                q.push({t->right,x-1});
            }
            if(m[t] && !vis[m[t]->val]){
                vis[m[t]->val]=1;
                q.push({m[t],x-1});
            }
        }

        return ans;
    }
};