//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
   string multiply(string num1,string num2){
        if(num1=="0" || num2=="0") return "0";
      vector<int>num((num1.size()+num2.size()),0);
      for(int i=num1.size()-1;i>=0;i--){
          for(int j=num2.size()-1;j>=0;j--){
              num[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
              num[i+j]+=num[i+j+1]/10;
              num[i+j+1]%=10;
          }
      }
      int i=0;
      while(num[i]==0 && i<num.size()) i++;
      string res="";
      while(i<num.size()){
          res.push_back(num[i++]+'0');
      }
      return res;
    }
    
    string multiplyStrings(string s1, string s2) {
       string res1="",res2="";
        if(s1[0]=='-'){
            int i=1;
            while(i<s1.size()) res1.push_back(s1[i++]);
        }
        else{
            res1=s1;
        }
        if(s2[0]=='-'){
            int j=1;
            while(j<s2.size()) res2.push_back(s2[j++]);
        }
        else{
            res2=s2;
        }
        string res=multiply(res1,res2);
        if(s1[0]=='-'&& s2[0]=='-') return res;
        if(s1[0]=='-'||s2[0]=='-') return '-'+res;
        return res;
    }
};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends