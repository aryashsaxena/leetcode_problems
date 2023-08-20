class Solution {
public:
    int f(int i,int k,vector<int>&nums,vector<vector<int>>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i][k]!=-1) return dp[i][k];

        int mn=INT_MAX;
        for(int j=1;j<=3;j++){
            if(j<k) continue;
            if(nums[i]==j) mn=min(mn,f(i+1,j,nums,dp));
            else mn=min(mn,1+f(i+1,j,nums,dp));
        }

        return dp[i][k]=mn;
    }

    int minimumOperations(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(4,-1));
        return f(0,1,nums,dp);
    }
};