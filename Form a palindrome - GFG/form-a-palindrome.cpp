//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int f(int i,int j,string &s,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=INT_MAX-100;
        if(s[i]==s[j]){
            ans=f(i+1,j-1,s,dp);
        }
        else{
            ans=1+min(f(i,j-1,s,dp),f(i+1,j,s,dp));
            // ans=min(ans,2+f(i+1,j-1,s,dp));
        }
        return dp[i][j]=ans;
    }
    
    int countMin(string str){
    //complete the function here
        vector<vector<int>> dp(str.size()+1,vector<int>(str.size()+1,-1));
        return f(0,str.size()-1,str,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends