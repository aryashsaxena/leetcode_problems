class Solution {
public:

    int f(int n,vector<int>&dp){
        if(dp[n]!=-1) return dp[n];

        int ans=1;
        for(int i=1;i<=n;i++){

            int x=i*f(n-i,dp);
            if(ans<x){
                cout<<x<<" ";
                ans=x;
            }
        }
        return dp[n]=ans;
    }

    int integerBreak(int n) {
        if(n<=3) return n-1;
        vector<int> dp(n+1,-1);

        return f(n,dp);
    }
};