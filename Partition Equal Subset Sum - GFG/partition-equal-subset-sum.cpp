//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int n;
    bool f(int i,long long sum,int nums[],vector<vector<int>>&dp){
        if(sum==0) return true;
        if(i==0){
            return nums[i]==sum;
        }
        if(i<0) return false;
    
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        bool ntake=f(i-1,sum,nums,dp);
        bool take=false;
        if(nums[i]<=sum){
            take =f(i-1,sum-nums[i],nums,dp);
        }
        return dp[i][sum]=ntake | take;
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        n=N;
        long long sum=0;
        for(int i=0;i<N;i++) sum+=arr[i];
        
        if(sum&2!=0) return 0;
        
        vector<vector<int>>dp(N+1,vector<int>(sum/2 + 1,-1));
        return f(n-1,sum/2,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends