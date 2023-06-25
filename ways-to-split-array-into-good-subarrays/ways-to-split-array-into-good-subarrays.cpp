class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int mod=1e9+7;
        vector<int> v;
        long long ans=1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                v.push_back(i);
            }
        }

        if(v.size()==0) return 0;

        for(int i=1;i<v.size();i++){
            ans=(ans*(1LL*v[i]-v[i-1]))%mod;
        }

        return ans;
    }
};