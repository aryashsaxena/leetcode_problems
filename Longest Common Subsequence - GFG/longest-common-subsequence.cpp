//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i>=s.size() || j>=t.size())  return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]){
            return dp[i][j]=1+f(i+1,j+1,s,t,dp);
        }
        else{
            return dp[i][j]=max(f(i+1,j,s,t,dp),f(i,j+1,s,t,dp));
        }
    }
    
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return f(0,0,s1,s2,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends