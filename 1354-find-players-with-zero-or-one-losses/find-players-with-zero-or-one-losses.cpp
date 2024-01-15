class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        set<int> st;
        map<int,int> m;

        for(int i=0;i<matches.size();i++)
        {
            st.insert(matches[i][0]);
            m[matches[i][1]]++;
        }

        vector<vector<int>> ans;
        vector<int>v1,v2;

        for(auto it:st)
        {
            if(!m.count(it))
            v1.push_back(it);
        }
        for(auto it:m)
        {
            if(it.second==1)
            v2.push_back(it.first);
        }
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};