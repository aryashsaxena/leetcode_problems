//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    long long int f(int i,int x,int coins[],vector<vector<long long int>>&dp){
        if(x==0) return 1;
        if(i==0){
            if(x%coins[i]==0) return 1;
            return 0;
        }
        
        if(dp[i][x]!=-1) return dp[i][x];
        
        long long int  ntake=f(i-1,x,coins,dp);
        long long int take=0;
        if(x-coins[i]>=0){
            take=f(i,x-coins[i],coins,dp);
        }
        return dp[i][x]=take+ntake;
    }
    
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int >> dp(N+1,vector<long long int >(sum+1,-1));
        return f(N-1,sum,coins,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends