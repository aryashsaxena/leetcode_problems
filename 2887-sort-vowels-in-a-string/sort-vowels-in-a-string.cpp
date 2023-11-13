class Solution {
public:
        bool check(char ch){
             if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
            return false;
        }
    
    string sortVowels(string s) {
        vector<char> v;
        
        for(auto i:s){
            
            char ch=tolower(i);
            if(check(ch))
            v.push_back(i);
        }
        
        sort(v.begin(),v.end());
        string ans="";
        int j=0;
        for(int i=0;i<s.size();i++){
            if(!check(tolower(s[i]))){
                ans+=s[i];
            }
            else{
                ans+=v[j++];
            }
        }
        return ans;
        
    }
};