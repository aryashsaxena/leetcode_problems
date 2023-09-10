class Solution {
public:
    int mod=1e9+7;
    
    long long f(long long i,long long j,vector<vector<long long>>&dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0 || i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        long long ans=((i%mod)*(f(i-1,j,dp)%mod))%mod;
        ans=ans%mod + (((j-i)%mod)*(f(i,j-1,dp)%mod))%mod;
        return dp[i][j]=ans;
    }

    int countOrders(int n) {
        vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
        return f(n,n,dp);
    }
};