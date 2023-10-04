//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        
        int x=0;
        int i=0;
        while(i<s.size()){
           if(i+1<s.size() && m[s[i+1]]>m[s[i]]){
               x+=m[s[i+1]]-m[s[i]];
               i++;
           }
           else x+=m[s[i]];
           
            i++;
        }
        return x;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends