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
    int kthSmallest(TreeNode* root, int k) {
        
        stack<TreeNode*> st;
        TreeNode* cur=root;

        while(cur){
            st.push(cur);
            cur=cur->left;
        }

        while(!st.empty()){
            auto t=st.top();
            st.pop();

            if(k==1) return t->val;

            k--;
            if(t->right){
                st.push(t->right);
                TreeNode* temp=t->right->left;
                while(temp){
                    st.push(temp);
                    temp=temp->left;
                }
            }
        }

        return -1;
    }
};