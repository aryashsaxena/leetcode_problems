class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<k;i++) pq.push({nums[i],i});
        vector<int> ans;
        ans.push_back(pq.top().first);

        int i=0,j=k;
        while(j<nums.size()){
            pq.push({nums[j],j});
            while(!pq.empty() && pq.top().second<=i) pq.pop();

            ans.push_back(pq.top().first);
            j++;
            i++;
        }
        return ans;
    }
};