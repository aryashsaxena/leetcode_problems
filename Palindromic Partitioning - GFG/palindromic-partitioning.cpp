//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check(string &s){
        int i=0,j=s.size()-1;
        
        while(i<j){
            if(s[i]!=s[j]) return false;
            
            i++;
            j--;
        }
        return true;
    }
    
    int f(int i,string &s,vector<int>&dp){
        if(i>=s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
    
        
        string t="";
        int ans=s.size()-i;
        for(int j=i;j<s.size();j++){
            t+=s[j];
            
            if(check(t)){
                ans=min(ans,1+f(j+1,s,dp));
            }
        }    
        return dp[i]=ans;
    }
    
    int palindromicPartition(string str)
    {
        // code here
        vector<int> dp(str.size()+1,-1);
        return f(0,str,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends