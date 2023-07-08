class Solution {
public:
    long long putMarbles(vector<int>& nums, int k) {
            vector<long long> v;

            for(int i=0;i<nums.size()-1;i++){
                long long x=0;
                x+=nums[i]+nums[i+1];
                v.push_back(x);
            }

            sort(v.begin(),v.end());
            long long count=0;

            for(int i=0;i<k-1;i++){
                count+=v[v.size()-1-i]-v[i];
            }
            return count;
    }
};