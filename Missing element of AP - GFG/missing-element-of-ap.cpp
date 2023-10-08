//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMissing(int arr[], int n) {
        // code here
        int d=(arr[n-1]-arr[0])/n;
        
        int l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)>>1;
            
            if((arr[mid]-arr[0])/d == mid){
                l=mid+1;
            }
            else h=mid-1;
        }
        return arr[h]+d;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMissing(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends