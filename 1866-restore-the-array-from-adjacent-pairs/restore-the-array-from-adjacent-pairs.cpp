class Solution {
public:
    vector<int> ans;

    void f(int i,unordered_map<int,vector<int>>&adj,unordered_set<int>&vis){
        ans.push_back(i);  
        vis.insert(i);

        for(auto j:adj[i]){
            if(vis.count(j)) continue;
            f(j,adj,vis);
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adj) {
        unordered_map<int,vector<int>> mp;
        unordered_map<int,int> fq;

        for(auto i:adj){
            mp[i[1]].push_back(i[0]);
            mp[i[0]].push_back(i[1]);
            fq[i[0]]++;
            fq[i[1]]++;
        }

        unordered_set<int> vis;
        for(auto it:fq){
            if(it.second==1){
                f(it.first,mp,vis);
                break;
            }
        }

        return ans;
    }
};