class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<long long> sum(nums.size(),0);
        int n=nums.size();

        sum[0]=nums[0];
        for(int i=1;i<n;i++){
            sum[i]+=sum[i-1]+nums[i];
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            int x=(sum[n-1]-sum[i])-(n-i-1)*nums[i];
            
            // cout<<sum[n-1]-sum[i]<<"-"<<(n-i-1)*nums[i]<<"= "<<x<<" ";
            if(i>0) x+=(i*nums[i])-(sum[i-1]);

            ans.push_back(x);
        }

        return ans;
    }
};