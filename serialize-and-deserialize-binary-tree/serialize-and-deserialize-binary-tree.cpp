/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        queue<TreeNode*> q;
        q.push(root);

        string ans="";
        while(!q.empty()){
           TreeNode* t=q.front();
           q.pop();

           if(!t) ans+="#,";
           else ans+=to_string(t->val)+",";

           if(t){
               q.push(t->left);
               q.push(t->right);
           }
        }

        cout<<ans<<endl;
        return ans;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
        return NULL;

        stringstream s(data);
        string t;
        getline(s,t,',');

        queue<TreeNode*> q;
        TreeNode* root=new TreeNode(stoi(t));
        q.push(root);

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            getline(s,t,',');
            if(t=="#") node->left=NULL;
            else{
                node->left=new TreeNode(stoi(t));
                q.push(node->left);
            }

            getline(s,t,',');
            if(t=="#") node->right=NULL;
            else{
                node->right=new TreeNode(stoi(t));
                q.push(node->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));