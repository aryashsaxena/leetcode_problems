//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int f(int i,int n,int arr[],vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int ntake=0+f(i+1,n,arr,dp);
        int take=arr[i]+f(i+2,n,arr,dp);
        
        return dp[i]=max(take,ntake);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n+1,-1);
        return f(0,n,arr,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends