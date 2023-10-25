class Solution {
public:
    // int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    //     if(j>=t.size()) return 1;
    //     if(i>=s.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     if(s[i]==t[j]){
    //         return dp[i][j]=f(i+1,j+1,s,t,dp)+f(i+1,j,s,t,dp);
    //     }
    //     else return dp[i][j]=f(i+1,j,s,t,dp);
    // }

    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(s.size()+1,vector<long long>(t.size()+1,0));

        for(int i=0;i<=s.size();i++){
            dp[i][t.size()]=1;
        }
        long long mod=1e9+7;

        for(int i=s.size()-1;i>=0;i--){
            for(int j=t.size()-1;j>=0;j--){
                if(s[i]==t[j]){
                    dp[i][j]=(dp[i+1][j+1]%mod+dp[i+1][j]%mod)%mod;
                }
                else dp[i][j]=dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};