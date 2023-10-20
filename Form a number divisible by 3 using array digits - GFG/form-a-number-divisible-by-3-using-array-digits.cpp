//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int get(int x){
        int c=0;
        while(x){
            c+=(x%10);
            x/=10;
        }
        return c;
    }
    
    int isPossible(int N, int arr[]) {
        // code here
        int count=0;
        for(int i=0;i<N;i++){
            count+=get(arr[i]);
        }
        return count%3==0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends