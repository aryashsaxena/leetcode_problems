class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }

        vector<vector<int>> ans;
        for(auto i:m){
            vector<int> v;
            for(auto j:i.second){
                if(v.size()==i.first){
                    ans.push_back(v);
                    v.clear();
                }
                v.push_back(j);
            }
            if(v.size()==i.first){
                ans.push_back(v);
            }
        }
        return ans;
    }
};