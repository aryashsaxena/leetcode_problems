class Solution {
public:
    const int mod=1e9+7;

    int f(int n,int k,int tar,vector<vector<int>>&dp){
        if(n==0 && tar==0) return 1;
        if(tar<n || (n*k)<tar) return 0;
        if(dp[n][tar]!=-1) return dp[n][tar];

        int count=0;

        for(int i=1;i<=k;i++){
            if(tar<i) break;

            count=(count + f(n-1,k,tar-i,dp)%mod)%mod;
        } 

        return dp[n][tar]=count;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

        if(n==0 && target==0) return 1;
        if(target < n || (n*k)<target) return 0;

        return f(n,k,target,dp);
    }
};