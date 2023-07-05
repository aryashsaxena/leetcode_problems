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

class BST{
    public:
    bool reverse=true;
    stack<TreeNode*> st;

    BST(TreeNode* root,bool flag){
        reverse=flag;
        pushAll(root);
    }

    int next(){
        TreeNode* cur=st.top();
        st.pop();

        if(!reverse) pushAll(cur->right);
        else pushAll(cur->left);

        return cur->val;
    }

    void pushAll(TreeNode* root){

        TreeNode* cur=root;
        while(cur){
            st.push(cur);
            if(reverse) cur=cur->right;
            else cur=cur->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BST  left(root,false);
        BST right(root,true);

        int i=left.next();
        int j=right.next();

        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=left.next();
            else j=right.next();
        }

        return false;
    }
};