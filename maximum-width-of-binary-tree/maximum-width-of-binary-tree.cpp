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
    unordered_map<int,unsigned long long> dp;

    unsigned long long f(TreeNode* root,int l,unsigned long long idx){
        if(!root) return 0;
        
        if(!dp.count(l)) dp[l]=idx;

        unsigned long long left=f(root->left,l+1,(1LL*2*idx));
        unsigned long long right=f(root->right,l+1,(1LL*2*idx)+1);
        unsigned long long ans=idx-dp[l]+1;
        return max({ans,left,right});
    }

    int widthOfBinaryTree(TreeNode* root) {
       
        return f(root,0,0);
    }
};