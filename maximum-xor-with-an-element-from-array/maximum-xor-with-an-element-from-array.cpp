class Trie{
    private:
    class Node{
        public:
        Node* link[2];
    };

    public:
    Node* root;

    Trie(){
        root=new Node();
    }

    void insert(int n){
        Node* node=root;

        for(int i=31;i>=0;i--){
            int bit=(n>>i) & 1;
            
            if(!node->link[bit]){
                node->link[bit]=new Node();
            }
            node=node->link[bit];
        }
    }

    int get(int n){
        int ans=0;
        Node* node=root;

        for(int i=31;i>=0;i--){
            int bit=(n>>i) & 1;

            if(node->link[!bit]){
                ans=ans|(1<<i);
                node=node->link[!bit];
            }
            else if(node->link[bit])
            node=node->link[bit];
            else return -1;
        }
        return ans;
    }
    
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        Trie trie;

        sort(nums.begin(),nums.end());

        for(int i=0;i<q.size();i++)
        q[i].push_back(i);

        sort(q.begin(),q.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });

        int i=0,j=0;
        vector<int> ans(q.size(),-1);
        while(j<q.size()){
            if(i<nums.size() && nums[i]<=q[j][1]){
                trie.insert(nums[i]);
                i++;
            }
            else{
                int x=trie.get(q[j][0]);
                ans[q[j][2]]=x;
                j++;
            }
        }

        return ans;
    }
};