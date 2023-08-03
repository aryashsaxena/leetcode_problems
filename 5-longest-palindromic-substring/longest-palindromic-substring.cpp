class Solution {
public:
    int f(int i,int j,string &s,vector<vector<int>>&dp){
        if(i>=j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        bool ans=(s[i]==s[j]) && f(i+1,j-1,s,dp);
        return dp[i][j]=ans; 
    }

    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        int mx=-1,st=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(f(i,j,s,dp)){
                    if(j-i+1>mx){
                        mx=j-i+1;
                        st=i;
                    }
                }
            }
        }

        return s.substr(st,mx);
    }
};