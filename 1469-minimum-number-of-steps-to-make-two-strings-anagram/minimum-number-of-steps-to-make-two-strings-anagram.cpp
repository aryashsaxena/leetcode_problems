class Solution {
public:
    int minSteps(string s, string t) {
        map<int,int> mp;

        for(auto i:t) mp[i]++;
        for(auto i:s) mp[i]--;

        int count=0;
        for(auto i:mp) count+=abs(i.second);

        return count/2;
    }
};