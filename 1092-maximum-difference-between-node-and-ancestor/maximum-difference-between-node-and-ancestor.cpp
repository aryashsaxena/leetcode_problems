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
     
    int f(TreeNode* root,int mn,int mx)
    {
        if(!root) return 0;

        mn=min(root->val,mn);
       
        mx=max(root->val,mx);

        int l=f(root->left,mn,mx);

        int r=f(root->right,mn,mx);

        return max((mx-mn),max(l,r));
    }

    int maxAncestorDiff(TreeNode* root) {
        
       return f(root,root->val,root->val);
    }
};