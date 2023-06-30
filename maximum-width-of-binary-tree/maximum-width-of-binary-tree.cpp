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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});
        int ans=0;

        while(!q.empty()){
            int sz=q.size();
            int mn=q.front().second;
            int fst=0,lst;

            while(sz--){
                auto it=q.front();
                q.pop();

                int cur=it.second-mn;

                if(sz==0) lst=cur;
                if(it.first->left) q.push({it.first->left,1LL*2*cur});
                if(it.first->right) q.push({it.first->right,1LL*2*cur+1});
            }

            ans=max(ans,lst-fst+1);
        }
        return ans;
    }
};