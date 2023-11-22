class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;

        vector<vector<int>> v;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                v.push_back({i+j,j,i});
            }
        }

        sort(v.begin(),v.end(),[](auto &a,auto &b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });

        for(auto i:v) ans.push_back(nums[i[2]][i[1]]);
        
        return ans;
    }
};