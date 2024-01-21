class Solution {
public:

    int f(int i,vector<int>& nums,vector<int>&dp)
    {
        if(i>=nums.size())
        return 0;
       
        if(dp[i]!=-1)
        return dp[i];

        int take=nums[i]+f(i+2,nums,dp);
        int ntake=0+f(i+1,nums,dp);

        return dp[i]=max(take,ntake);
    }

    int rob(vector<int>& nums) {
        
        vector<int>dp(nums.size()+1,-1);
        return f(0,nums,dp);
    }
};