class Solution {
public:
    #define ll long long;
    #define pll pair<long long,long long>;

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<long long,long long>> v;
        priority_queue<long long ,vector<long long>,greater<long long>> pq;
        for(int i=0;i<nums1.size();i++){
            v.push_back({nums2[i],nums1[i]});
        }

        sort(v.rbegin(),v.rend());
        long long count=0;

        for(int i=0;i<k;i++){
            count+=v[i].second;
            pq.push(v[i].second);
        }
        long long mx=count*v[k-1].first;

        for(int i=k;i<nums1.size();i++){
            count-=pq.top();
            pq.pop();

            count+=v[i].second;
            pq.push(v[i].second);

            mx=max(mx,count*v[i].first);
        }
        return mx;
    }
};