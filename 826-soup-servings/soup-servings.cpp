class Solution {
public:
    double f(int n,int m,vector<vector<double>> &dp){
        if(n<=0 && m<=0) return 0.5;
        if(n<=0) return 1.0;
        if(m<=0) return 0.0;

        if(dp[n][m]!=-1) return dp[n][m];

        double ans=f(n-100,m,dp)+f(n-75,m-25,dp)+f(n-50,m-50,dp)+f(n-25,m-75,dp);
        return dp[n][m]=ans/4.0;
    }

    double soupServings(int n) {
        if(n>=6000) return 1;
        
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
        return f(n,n,dp);
    }
};