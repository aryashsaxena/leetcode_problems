class Solution {
public:
    set<vector<int>> st;

    int f(int x,vector<int>&v,vector<int>&nums,vector<int>&dp){
        if(x==0){
            if(!st.count(v)){
                st.insert(v);
                return 1;
            }
            return 0;
        }
        if(dp[x]!=-1) return dp[x];

        int count=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]<=x){
                v.push_back(nums[j]);
                count+=f(x-nums[j],v,nums,dp);
                v.pop_back();
            }
        }
        return dp[x]=count;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        vector<int> v;
        return f(target,v,nums,dp);
    }
};