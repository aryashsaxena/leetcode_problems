//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string> ans;
    
    void f(string &s,string &t,vector<int>&vis){
        if(t.size()==s.size()){
            ans.push_back(t);
            return;
        }
        
        for(int i=0;i<s.size();i++){
            if(!vis[i]){
                vis[i]=1;
                t.push_back(s[i]);
                f(s,t,vis);
                vis[i]=0;
                t.pop_back();
            }
        }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        string t="";
        vector<int> vis(S.size(),0);
        f(S,t,vis);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends