//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string s, string t) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
	    
	    for(int i=1;i<=s.size();i++){
	        for(int j=1;j<=t.size();j++){
	            if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
	            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    
	    return s.size()+t.size()-2*dp[s.size()][t.size()];
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends