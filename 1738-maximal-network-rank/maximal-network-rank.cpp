class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<int>> m;
        for(auto i:roads){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }

        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;

                int sz=m[i].size()+m[j].size();
                if(find(m[j].begin(),m[j].end(),i)!=m[j].end()){
                    sz--;
                }
                mx=max(mx,sz);
            }
        }
        return mx;
    }
};