class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        return dp[i]=nums[i]+min(f(i+1,nums,dp),f(i+2,nums,dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);

        int ans=f(0,cost,dp);

        vector<int> dp2(cost.size()+1,-1);
        ans=min(ans,f(1,cost,dp2));
        return ans;
    }
};