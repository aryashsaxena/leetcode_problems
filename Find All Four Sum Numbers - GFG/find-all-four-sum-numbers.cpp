//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        
        int i=0;
        while(i<arr.size()){
            int j=i+1;
            while(j<arr.size()){
                int tg=k-(arr[i]+arr[j]);
                
                int l=j+1,h=arr.size()-1;
                while(l<h){
                    if(arr[l]+arr[h]==tg){
                        ans.push_back({arr[i],arr[j],arr[l],arr[h]});
                        
                        int tl=l,th=h;
                        while(l<h && arr[tl]==arr[l]) l++;
                        
                        while(l<h && arr[th]==arr[h]) h--;
                    }
                    else if(arr[l]+arr[h]<tg) l++;
                    else h--;
                }
                
                int tj=j;
                while(j<arr.size() && arr[tj]==arr[j]) j++;
            }
            
            int ti=i;
            while(i<arr.size() && arr[ti]==arr[i]) i++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends