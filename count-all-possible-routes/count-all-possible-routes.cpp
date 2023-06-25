class Solution {
public:
    int mod=1e9+7;

    int f(int i,int x,int n,vector<int>&nums,vector<vector<int>>&dp){
        if(i<0 || i>=nums.size() || x<0) return 0;
        // if(i==n) return 1;
        if(dp[i][x]!=-1) return dp[i][x];
        int ans= i==n ? 1 : 0;
        
        for(int j=0;j<nums.size();j++){
            if(i==j) continue;

            ans=ans%mod + (f(j,x-abs(nums[i]-nums[j]),n,nums,dp)%mod);
        }

        return dp[i][x]=ans%mod;
    }

    int countRoutes(vector<int>& nums, int start, int finish, int fuel) {
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(fuel+1,-1));
        return f(start,fuel,finish,nums,dp)%mod;
    }
};