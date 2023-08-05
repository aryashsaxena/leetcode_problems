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
    vector<TreeNode*> f(int i,int n,map<pair<int,int>,vector<TreeNode*>>&dp){
        vector<TreeNode*> ans;
        if(i>n){
            ans.push_back(NULL);
            return ans;
        }
        if(dp.count({i,n})) return dp[{i,n}];

        for(int j=i;j<=n;j++){
            vector<TreeNode*> left=f(i,j-1,dp);
            vector<TreeNode*> right=f(j+1,n,dp);

            // TreeNode* root=new TreeNode(j);
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root=new TreeNode(j,l,r);
                    // root->left=l;
                    // root->right=r;
                    ans.push_back(root);
                }
            }
        }
        return dp[{i,n}]=ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        
        map<pair<int,int>,vector<TreeNode*>> dp;
        return f(1,n,dp);
    }
};