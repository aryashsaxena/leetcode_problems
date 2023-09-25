class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hash(27,0);
        for(auto i:t){
            hash[i-'a']++;
        }

        for(auto i:s) hash[i-'a']--;

        for(int i=0;i<27;i++){
            if(hash[i]==1) return i+'a';
        }
        return '#';
    }
};