class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
        int mx=max(s.size(),t.size());
        vector<int> prev(mx+1,0),cur(mx+1,0);

        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]){
                    cur[j]=1+prev[j-1];
                }
                else cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }

        // int i=s.size(),j=t.size();
        // string ans="";

        // while(i>0 && j>0){
        //     if(s[i-1]==t[j-1]){
        //         ans=s[i-1]+ans;
        //         i--;
        //         j--;
        //     }
        //     else if(dp[i-1][j]>dp[i][j-1]) i--;
        //     else j--;
        // }
        // cout<<ans<<endl;
        return prev[t.size()];
    }
};