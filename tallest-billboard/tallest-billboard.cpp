class Solution {
public:

    int f(int i,int x,vector<int>&nums,vector<vector<int>>&dp){
        if(i>=nums.size()){
            return x==0 ? 0 : INT_MIN;
        }
        if(dp[i][x+5000]!=-1) return dp[i][x+5000];

        int ntake=0+f(i+1,x,nums,dp);
        int take=nums[i]+max(f(i+1,x+nums[i],nums,dp),f(i+1,x-nums[i],nums,dp));

        return dp[i][x+5000]=max(take,ntake);
    }

    int tallestBillboard(vector<int>& rods) {
         vector<vector<int>>dp(21,vector<int>(10002,-1));

        int ans=f(0,0,rods,dp); 
        return ans<0 ? 0  :  ans/2;   
    }
};