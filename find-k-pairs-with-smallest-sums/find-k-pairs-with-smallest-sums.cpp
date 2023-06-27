class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        set<pair<int,int>> st;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        st.insert({0,0});
        pq.push({nums1[0]+nums2[0],{0,0}});

        while(k-- && !pq.empty()){
            auto p=pq.top();
            pq.pop();
            int i=p.second.first,j=p.second.second;

            ans.push_back({nums1[i],nums2[j]});

            if(i+1<nums1.size() && !st.count({i+1,j})){
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                st.insert({i+1,j});
            } 

            if(j+1<nums2.size() && !st.count({i,j+1})){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                st.insert({i,j+1});  
            } 

            if(i+1<nums1.size() && j+1<nums2.size() && !st.count({i+1,j+1})){
                pq.push({nums1[i+1]+nums2[j+1],{i+1,j+1}});
                st.insert({i+1,j+1});
            } 
        }

        return ans;
    }
};