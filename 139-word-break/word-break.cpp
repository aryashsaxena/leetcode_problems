class Solution {
public:
    bool f(int i,string &s,unordered_set<string>&st,vector<int> &dp){
        if(i>=s.size()) return true;
        if(dp[i]!=-1) return dp[i];

        string t="";
        for(int j=i;j<s.size();j++){
            t+=s[j];
            if(st.count(t)){
                if(f(j+1,s,st,dp)) return dp[i]=true;
            }
        }
        return dp[i]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        vector<int> dp(s.size()+1,-1);

        for(auto i:wordDict) st.insert(i);
        return f(0,s,st,dp);
    }
};