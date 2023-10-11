class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flr, vector<int>& nums) {
        sort(flr.begin(),flr.end());

        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }

        sort(v.begin(),v.end());

        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> ans(nums.size());

        int j=0;
        for(auto i:v){
            while(j<flr.size() && flr[j][0]<=i.first){
                pq.push(flr[j][1]);
                j++;
            }

            while(!pq.empty() && pq.top()<i.first){
                pq.pop();
            }

            ans[i.second]=pq.size();
        }
        return ans;
    }
};