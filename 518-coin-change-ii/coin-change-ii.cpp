class Solution {
public:
    int f(int i,int x,vector<int>&coins,vector<vector<int>>&dp){
        if(x==0) return 1;
        if(i==0){
            if(x%coins[i]==0) return 1;
            return 0;
        }
        if(dp[i][x]!=-1) return dp[i][x];
        
        int ntake=f(i-1,x,coins,dp);
        int take=0;
        if(x-coins[i]>=0){
            take=f(i,x-coins[i],coins,dp);
        }
        return dp[i][x]=ntake+take;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return f(coins.size()-1,amount,coins,dp);
    }
};