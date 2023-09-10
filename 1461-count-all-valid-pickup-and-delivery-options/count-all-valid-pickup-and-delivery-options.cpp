class Solution {
public:
    long long mod=1e9+7;
    long long f(long long i,long long n,vector<long long>&dp){
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];

        long long ans=((n-i)*(2*(n-i)-1))%mod;
        ans=((ans%mod)*(f(i+1,n,dp)%mod))%mod;
        return dp[i]=ans;
    }

    int countOrders(int n) {
       vector<long long> dp(n+1,-1);
       return f(0,n,dp);
    }
};