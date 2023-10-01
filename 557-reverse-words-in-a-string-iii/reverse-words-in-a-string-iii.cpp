class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        
        string t="";
        for(auto i:s){
            if(i==' '){
                if(ans.size()==0) ans=t;
                else ans+=" "+t;
                t="";
            }
            else t=i+t;
        }

        if(ans.size()==0) ans=t;
        else ans+=" "+t;

        return ans;
    }
};