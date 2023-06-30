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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        map<int,map<int,vector<int>>>m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [t,i]=q.front();
                q.pop();

                int l=i.first,h=i.second;
                m[h][l].push_back(t->val);
                if(t->left) q.push({t->left,{l+1,h-1}});
                if(t->right) q.push({t->right,{l+1,h+1}});
            }
        }

        for(auto i:m){
            vector<int> v;
            for(auto j:i.second){
                  vector<int> t=j.second;
                  sort(t.begin(),t.end());

                  for(auto k:t) v.push_back(k);
            }
            ans.push_back(v);
        }

        return ans;
    }
};