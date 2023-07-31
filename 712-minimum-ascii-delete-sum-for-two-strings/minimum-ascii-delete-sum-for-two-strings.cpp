class Solution {
public:
    int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i>=s.size()  && j>=t.size() ) return 0;
        if(i>=s.size()){
            int count=0;
            while(j<t.size()){
                count+=int(t[j]);
                j++;
            }
            return count;
        }
         if(j>=t.size()){
            int count=0;
            while(i<s.size()){
                count+=int(s[i]);
                i++;
            }
            return count;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]){
            return dp[i][j]=f(i+1,j+1,s,t,dp);
        }
        else{
            dp[i][j]=min(int(s[i]) + f(i+1,j,s,t,dp) , int(t[j]) + f(i,j+1,s,t,dp) );
            return dp[i][j];
        }
    }

    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        
        return f(0,0,s1,s2,dp);
    }
};