class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx=0;
        unordered_set<char> st;
        int l=0,h=0;
        while(h<s.size()){
            while(st.count(s[h]) && l<h){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[h]);
            mx=max(mx,h-l+1);
            h++;
        }
        return mx;
    }
};