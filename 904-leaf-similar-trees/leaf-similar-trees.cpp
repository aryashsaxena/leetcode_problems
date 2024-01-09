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
void f(TreeNode* root,vector<int>&v)
{
    if(!root->left && !root->right)
    {
        v.push_back(root->val);
        return ;
    }

    if(root->left)
    f(root->left,v);

    if(root->right)
    f(root->right,v);

}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> v1,v2;

        f(root1,v1);
        f(root2,v2);

        return v1==v2;
        
    }
};