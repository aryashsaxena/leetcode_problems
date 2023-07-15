class Solution {
public:
    int f(int i,int k,vector<vector<int>>&nums,vector<vector<int>>&dp){
        if(i>=nums.size() || k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];

        int ntake=f(i+1,k,nums,dp);
        int take=0;
        int j=i+1;
        while(j<nums.size() && nums[i][1]>=nums[j][0]) j++;

        take=nums[i][2]+f(j,k-1,nums,dp);
        return dp[i][k]=max(take,ntake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        
        sort(events.begin(),events.end());
        vector<vector<int>> dp(events.size()+1,vector<int>(k+1,-1));
        return f(0,k,events,dp);
    }
};