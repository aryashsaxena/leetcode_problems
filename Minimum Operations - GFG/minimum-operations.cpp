//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    
    int minOperation(int n)
    {
        //code here.
        int count=0;
        
        while(n){
            if(n&1){
                count++;
                n--;
            }
            else{
                count++;
                n/=2;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends