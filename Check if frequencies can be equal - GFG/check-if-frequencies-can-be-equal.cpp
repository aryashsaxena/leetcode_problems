//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    unordered_map<char,int> m;
	    for(auto ch:s){
	        m[ch]++;
	    }
	    
	    vector<int> v;
	    for(auto i:m){
	        v.push_back(i.second);
	    }
	    sort(v.begin(),v.end());
	    
	    if(v.size()==1) return true;
	    int fl=0;
	    
	    int c=0;
	    for(int i=1;i<v.size();i++){
	        if(v[i]-v[i-1]>=1 && c==1){
	            c=2;
	            break;
	        }
	        else if(v[i]-v[i-1]==1){
	            if(i==1 || v[i-1]!=1 || i==(v.size()-1))
	            c=1;
	            else{
	                c=2;
	                break;
	            }
	        }
	        else if(v[i]-v[i-1]>1){
	            if(v[i-1]==1 && i==1){
	                c=1;
	            }
	            else{
	                 c=2;
	                break;
	            }
	        }
	    }
	    if(c==1){
	        if(v.size()>1 && v.back()==v[v.size()-2] && v.back()>=2){
	            if(v[0]==v[1] && v[0]>=1)
	            c=2;
	            if(v[0]!=v[1] && v[0]!=1) c=2;
	        }
	    }
	    
	   // for(int i=1;i<v.size();i++){
	   //     if(v[i]!=v[i-1] && v[i]-v[i-1]>=1 && v[i-1]!=1){
	   //         fl=1;
	   //         break;
	   //     }
	       // if(v[i]-v[i-1]==1 && fl==0){
	       //     fl=1;
	       // }
	       // else if((v[i]-v[i-1]==1 && fl==1) || (v[i]-v[i-1]>1 && i!=1)){
	       //     fl=2;
	       //     break;
	       // }
	   // }
	    
	    if(c==2){
	        return false;
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends