class Solution {
public:
    bool buddyStrings(string s, string t) {
        if(s.size()!=t.size()) return false;

        int count=0;
        unordered_map<char,int> m;
        char x='#',y='#';
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                if(x=='#' && y=='#'){
                    x=s[i];
                    y=t[i];    
                }
                else if(t[i]!=x || s[i]!=y) return false;
                
                count++;
            }
            m[s[i]]++;
        }

        if(count==0){
            for(auto it:m){
                if(it.second>1) return true;
            }
        }
        return count==2;
    }
};