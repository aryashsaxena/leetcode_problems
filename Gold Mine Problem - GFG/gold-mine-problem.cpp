//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(i<0 || i>=mat.size() || j>=mat[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]=mat[i][j]+max({f(i+1,j+1,mat,dp),f(i,j+1,mat,dp),f(i-1,j+1,mat,dp)});
    }
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,f(i,0,M,dp));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends