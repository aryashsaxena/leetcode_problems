class Solution {
public:
    vector<int> topo(unordered_map<int,vector<int>>&mp,vector<int>&ind){
        queue<int> q;
        for(int i=0;i<ind.size();i++){
            if(ind[i]==0){
                q.push(i);
                // ans.push_back(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            auto u=q.front();
            ans.push_back(u);
            q.pop();

            for(auto v:mp[u]){
                ind[v]--;
                if(ind[v]==0){
                    q.push(v);
                }
            }
        }
        return ans.size()==ind.size() ? ans :vector<int>();
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& bfit) {
        for(auto &i:group){
            if(i==-1){
                i=m++;
            }
        }

        unordered_map<int,vector<int>> item,grp;
        vector<int> itemind(n,0),grpind(m,0);

        for(int i=0;i<n;i++){
            for(auto prev:bfit[i]){
                item[prev].push_back(i);
                itemind[i]++;

                if(group[i]!=group[prev]){
                    grp[group[prev]].push_back(group[i]);
                    grpind[group[i]]++;
                }
            }
        }

        vector<int> orderit=topo(item,itemind);
        vector<int> ordergrp=topo(grp,grpind);

        unordered_map<int,vector<int>> ans;
        for(auto i:orderit){
            ans[group[i]].push_back(i);
        }

        vector<int> res;
        for(auto i:ordergrp){
            res.insert(res.end(),ans[i].begin(),ans[i].end());
        }
        return res;
    }
};