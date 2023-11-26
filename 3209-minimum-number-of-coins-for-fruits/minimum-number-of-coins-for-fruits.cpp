class Solution {
public:
    int f(int i,int ch,vector<int>&nums,vector<vector<int>>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i][ch]!=-1) return dp[i][ch];
        
        if(ch==0){
            return dp[i][ch]=nums[i]+f(i+1,i+1,nums,dp);
        }
        else{
            return dp[i][ch]=min(nums[i]+f(i+1,i+1,nums,dp),f(i+1,ch-1,nums,dp));
        }
    }
    
    int minimumCoins(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(prices.size()+1,-1));
        
        return f(0,0,prices,dp);
    }
};