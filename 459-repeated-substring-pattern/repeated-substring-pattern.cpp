class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // if(s.size()&1) return false;

        set<string> st;
        string t="";
        for(int i=0;i<s.size()/2;i++){
            t+=s[i];
            st.insert(t);
        }

        for(auto it:st){
            string t=it;
            while(t.size()<s.size()){
                t+=it;
            }

            if(t==s){
                return true;
            }
        }
        return false;
    }
};