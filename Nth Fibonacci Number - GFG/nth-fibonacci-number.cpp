//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod=1e9+7;
    
    int f(int i,vector<int>&dp){
        if(i<=1) return i;
        if(dp[i]!=-1) return dp[i];
        
        return dp[i]=((f(i-1,dp)%mod)+(f(i-2,dp)%mod))%mod;
    }
    int nthFibonacci(int n){
        // code here
        vector<int> dp(n+1,-1);
        return f(n,dp)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends