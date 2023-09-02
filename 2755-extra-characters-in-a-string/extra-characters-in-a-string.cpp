class Solution {
public:
    unordered_set<string> st;

    int f(int i,string &s,vector<int>&dp){
        if(i>=s.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int ans=s.size()-i;
        for(int j=i;j<s.size();j++){
            string t="";
            for(int k=j;k<s.size();k++){
                t+=s[k];
                if(st.count(t)){
                     ans=min(ans,j-i+f(k+1,s,dp));
                }
            }
        }
        return dp[i]=ans;
    }
    int minExtraChar(string s, vector<string>& dict) {
        for(auto i:dict){
            st.insert(i);
        }
        vector<int> dp(s.size()+1,-1);
        return f(0,s,dp);
    }
};