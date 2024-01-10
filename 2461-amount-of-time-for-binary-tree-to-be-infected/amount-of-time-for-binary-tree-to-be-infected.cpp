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
    unordered_map<TreeNode*,TreeNode*> mp;
    TreeNode* tar;

    void mapp(TreeNode* ch,TreeNode* pr,int start){
        if(!ch) return ;

        if(ch->val==start) tar=ch;

        mp[ch]=pr;
        mapp(ch->left,ch,start);
        mapp(ch->right,ch,start);
    }

    int amountOfTime(TreeNode* root, int start) {
        mapp(root,NULL,start);

        int count=0;
        queue<TreeNode*> q;
        q.push(tar);
        unordered_set<int> st;

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto t=q.front();
                q.pop();
                cout<<t->val<<" ";

                if(st.count(t->val)) continue;

                if(t->left && !st.count(t->left->val)) q.push(t->left);
                if(t->right && !st.count(t->right->val)) q.push(t->right);
                if(mp[t]!=NULL && !st.count(mp[t]->val)){
                    q.push(mp[t]);
                    mp[t]=NULL;
                }
                st.insert(t->val);
            }
            if(!q.empty())
            count++;
        }
        return count;
    }
};