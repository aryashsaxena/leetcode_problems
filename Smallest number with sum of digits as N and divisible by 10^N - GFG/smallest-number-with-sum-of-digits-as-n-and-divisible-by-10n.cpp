//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
	public:
	string digitsNum(int n)
	{
	    // Code here.
	    int m=n;
	    string s="";
	    
	    while(m){
	        if(m>9){
	            s='9'+s;
	            m-=9;
	        }
	        else {
	            s=to_string(m) + s;
	            m=0;
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	        s+='0';
	    }
	    return s;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		string ans = ob.digitsNum(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends