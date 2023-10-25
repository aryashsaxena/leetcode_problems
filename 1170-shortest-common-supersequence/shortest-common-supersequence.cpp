class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));

        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        string cmn="";
        int i=s.size(),j=t.size();

        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                cmn=s[i-1]+cmn;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    
        string ans="";
        i=0,j=0;
        int k=0;
        while(i<s.size() && j<t.size()){
            if(s[i]!=cmn[k]){
                ans+=s[i];
                i++;
            }
            else if(t[j]!=cmn[k]){
                ans+=t[j];
                j++;
            }
            else{
                ans+=s[i];
                i++;
                j++;
                k++;
            }
        }

        while(i<s.size()){
            ans+=s[i];
            i++;
        }
        while(j<t.size()){
            ans+=t[j];
            j++;
        }
        return ans;
    }
};