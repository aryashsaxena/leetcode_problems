class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long count=0;

        int i=nums.size()-1;
        while(i--){
            if(nums[i]>=nums[i+1]){
                long long x=nums[i]/nums[i+1];
                if(nums[i]%nums[i+1]!=0){
                    x++;
                }
                count+=(x-1);

                nums[i]=nums[i]/x;
            }
        }
        return count;
    }
};