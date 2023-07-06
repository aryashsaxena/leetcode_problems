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

    int ans=0;

    vector<int> f(TreeNode *root ){
        if(!root ){
            return {0,INT_MAX,INT_MIN};
        }
        // if(!root->left && !root->right){
        //     return {root->val,root->val,root->val,1};
        // }

        vector<int> left=f(root->left);
        vector<int> right=f(root->right);

        if(root->val>left[2] && root->val<right[1]){
            ans=max(ans,root->val+left[0]+right[0]);

            return {root->val+left[0]+right[0] , min(root->val,left[1]), max(right[2],root->val)};
        }

        return {max(left[0],right[0]) ,INT_MIN,INT_MAX};
    }

    int maxSumBST(TreeNode* root) {
        vector<int> v=f(root);
        // return v[0];
        return ans;
    }
};