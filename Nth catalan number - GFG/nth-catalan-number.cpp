//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    long long mod=1e9+7;
    
    long long f(int i,int j,vector<vector<long long>>&dp){
        if(i==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        long long take=f(i-1,j,dp);
        long long ntake=0;
        if(i<j){
            ntake=f(i,j-1,dp);
        }
        return dp[i][j]=((take%mod)+(ntake%mod))%mod;
    }
    
    int findCatalan(int n) 
    {
        //code here
        // vector<vector<long long>> dp(n+1,vector<long long>(n+1,-1));
        // return f(n,n,dp)%mod;
        
        vector<long long> dp(n+1,0);
        
        dp[0]=1LL,dp[1]=1LL;
        
        for(int i=2;i<=n;i++){
            long long count=0;
            for(int j=0;j<i;j++){
                count=(count%mod)+(1LL*dp[j]*dp[i-j-1])%mod;
            }
            
            dp[i]=count%mod;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends