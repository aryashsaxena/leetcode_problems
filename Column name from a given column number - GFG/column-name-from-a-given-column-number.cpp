//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans="";
        
        while(n){
            int x;
             int f=0;
            
            if(n%26!=0){
                x=n%26;
            }
            else if(n<=26) x=n;
            else{
                x=26;
                n=(n/26);
                n--;
                f=1;
            }
            
            char ch=(x-1)+'A';
            ans= ch+ ans;
            
            if(n==26 && f==0) break;
            if(f==0)
            n/=26;

        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends