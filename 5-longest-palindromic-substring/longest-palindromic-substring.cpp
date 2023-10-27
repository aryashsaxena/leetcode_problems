class Solution {
public:
    vector<vector<int>> dp;

    int f(int i,int j,string &s){
        if(i>=j) return 1;
        if(s[i]!=s[j]) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        return  dp[i][j]=f(i+1,j-1,s); 
    }

    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        dp.resize(s.size()+1,vector<int>(s.size()+1,-1));

        int mx=0,st=0;

        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                if(f(i,j,s)){
                    if(mx<(j-i+1)){
                        mx=j-i+1;
                        st=i;
                    }
                }
            }
        }

        return s.substr(st,mx);
    }
};