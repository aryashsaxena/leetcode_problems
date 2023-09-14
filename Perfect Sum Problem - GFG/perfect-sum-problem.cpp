//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long mod=1e9+7;
	int N=0;
	
	long long f(int i,int sum,int nums[],vector<vector<long long>>&dp){
	    if(i<0){
	        if(sum==0) return 1;
	        return 0;
	    }
	    if(dp[i][sum]!=-1) return dp[i][sum];
	    
	    long long ntake=0,take=0;
	    ntake=f(i-1,sum,nums,dp)%mod;
	    if(nums[i]<=sum){
	        take=f(i-1,sum-nums[i],nums,dp)%mod;
	    }
	    return dp[i][sum]=(take+ntake)%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        // sort(arr,arr+n);
        N=n;
        vector<vector<long long>> dp(n+1,vector<long long>(sum+1,-1));
        return f(n-1,sum,arr,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends