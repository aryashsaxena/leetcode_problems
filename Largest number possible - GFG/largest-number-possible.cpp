//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int s){
        // code here
        if(n*9<s) return "-1";
        if(s==0){
            if(n==1) return "0";
            else return "-1";
        }
        
        string ans="";
        
        while(ans.size()!=n){
            if(s<9){
                ans.push_back(s+'0');
                s=0;
            }
            else{
                ans.push_back(9+'0');
                s-=9;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends