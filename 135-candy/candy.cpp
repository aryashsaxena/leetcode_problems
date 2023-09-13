class Solution {
public:
    int candy(vector<int>& rat) {
        int n=rat.size();
        vector<int> nums(n,1);

        for(int i=1;i<n;i++){
            if(rat[i]>rat[i-1]){
                nums[i]=nums[i-1]+1;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(rat[i]>rat[i+1] && nums[i]<=nums[i+1]){
                nums[i]=nums[i+1]+1;
            }
        }

        int ans=0;
        for(auto i:nums) ans+=i;
        return ans;
    }
};