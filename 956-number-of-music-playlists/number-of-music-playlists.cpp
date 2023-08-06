class Solution {
public:
    long long mod=1e9+7;

    long long f(int song,int unq,int n,int goal,int k,vector<vector<long long>>&dp){
        if(song==goal){
            if(unq==n){
                return 1;
            }
            return 0;
        }
        if(dp[song][unq]!=-1) return dp[song][unq];

        long long ans=0;
        if(n>unq)
        ans=ans%mod + (1LL*((n-unq)%mod)*(f(song+1,unq+1,n,goal,k,dp)%mod))%mod;

        if(unq>=k){
            ans=ans%mod + (1LL*((unq-k)%mod)*(f(song+1,unq,n,goal,k,dp)%mod))%mod;
        }
        return dp[song][unq]=ans%mod;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> dp(goal+1,vector<long long>(n+1,-1));
        return f(0,0,n,goal,k,dp)%mod;
    }
};