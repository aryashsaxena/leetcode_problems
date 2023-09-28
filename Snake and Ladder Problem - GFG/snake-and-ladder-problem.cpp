//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int f(int i,int n,unordered_map<int,int>&adj,vector<int>&dp){
        if(i==n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int ans=INT_MAX;
        for(int j=1;j<7;j++){
            int t=INT_MAX;
            int u=adj[i+j];
            
            if(u>i) 
                t = 1 + f(u,n,adj,dp);
            
            ans=min(ans,t);
        }
        return dp[i]=ans;
    }
    
    int minThrow(int N, int arr[]){
        // code here
        unordered_map<int,int> m;
        for(int i=1;i<=30;i++) m[i]=i;
        
        for(int i=0;i<(2*N);i+=2){
            m[arr[i]]=arr[i+1];
        }
        
        vector<int> dp(31,-1);
        return f(1,30,m,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends