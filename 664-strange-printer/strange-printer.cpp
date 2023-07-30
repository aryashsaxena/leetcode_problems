class Solution {
public:
    int f(int l,int r,string &s,vector<vector<int>>&dp){
        if(l==r) return 1;
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];

        int i=l+1;
        while(i<=r && s[i]==s[l]) i++;

        int ans=1+f(i,r,s,dp);

        for(int j=i;j<=r;j++){
            if(s[j]==s[l]){
                ans=min(ans,f(i,j-1,s,dp)+f(j,r,s,dp));
            }
        }
        return dp[l][r]=ans;
    }

    int strangePrinter(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));

        return f(0,s.size()-1,s,dp);
    }
};