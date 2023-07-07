/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void f(Node* node,unordered_map<Node*,Node*> &m,unordered_set<int> &vis){
        if(!node) return ;

        Node * x= new Node(node->val);
        m[node]=x;
        vis.insert(node->val);

        for(auto j:node->neighbors){
            if(!vis.count(j->val)) f(j,m,vis);
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node) return node;

        unordered_map<Node*,Node*> m;
        unordered_set<int> vis;

        f(node,m,vis);

        queue<Node*> q;
        q.push(node);
        Node* ans=m[node];
        unordered_set<int> st;
        st.insert(node->val);

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            vector<Node*> v;
            for(auto j:it->neighbors){
                v.push_back(m[j]);

                if(!st.count(j->val)){
                    st.insert(j->val);
                    q.push(j);
                }
            }
            m[it]->neighbors=v;
        }

        return ans;
    }
};