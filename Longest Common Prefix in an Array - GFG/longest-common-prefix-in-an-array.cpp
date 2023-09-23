//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int n)
    {
        // your code here
        sort(arr, arr+n);
        if(n==0)
        return "-1";
        if(n==1)
        return arr[0];
        string first= arr[0];
        string last=arr[n-1];
        int mini = min(arr[0].length(), arr[n-1].length());
        int i=0;
        while(i<mini && first[i]==last[i])
        {
            i++;
        }
        string s=arr[0].substr(0, i);
        if(s.length()==0)
        return "-1";
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends