//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
 int n = 0;
        
        for(int elem : nums) {
            n = n^elem;
        }
        
        int r = n&-n;
        int a = 0;
        int b = 0;
        
        for(int elem : nums) {
            if((r&elem) == 0) {
                a = a^elem;
            } else {
                b = b^elem;
            }
        }
        if(a<b) return {a,b};
        else return {b,a};
        
       
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends