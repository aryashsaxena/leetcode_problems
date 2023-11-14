class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,vector<int>> m;
        for(int i=0;i<s.size();i++){
            m[s[i]].push_back(i);
        }

        int count=0;
        for(auto i:m){
            unordered_set<char> chck;
            auto v=i.second;
            int l=v[0],h=v.back();

           for(int i=l+1;i<h;i++){
               if(!chck.count(s[i])){
                   count++;
                   chck.insert(s[i]);
               }
           }
        }
        return count;
    }
};