class Trie{
    private:
    class Node{
        public:
        Node *link[2];
    };

    public:
    Node* root;

    Trie(){
        root=new Node();
    }

    void insert(int n){
        Node* node=root;

        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;

            if(!node->link[bit]){
                node->link[bit]=new Node();
            }
            node=node->link[bit];
        }
    }

    int mxx(int n){
        Node* node=root;
        int ans=0;

        for(int i=31;i>=0;i--){
            int bit=(n>>i) & 1;
            
            if(node->link[!bit]){
                ans=ans| (1<<i);
                node=node->link[!bit];
            }
            else 
            node=node->link[bit];
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        Trie trie;
        for(auto i:nums){
            trie.insert(i);
        }

        int ans=0;
        for(auto i:nums){
            ans=max(ans,trie.mxx(i));
        }
        
        return ans;
    }
};