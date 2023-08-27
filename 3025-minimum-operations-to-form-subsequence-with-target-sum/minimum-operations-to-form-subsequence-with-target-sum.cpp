class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> bit(31,0);
        long long sum=0;

        for(int i=0;i<nums.size();i++){
            bit[(int)(log2(nums[i]))]++;
            sum+=nums[i];
        }

        if(sum<target) return -1;

        int i=0,count=0;

        while(i<30){
            if((1<<i) & target){
                if(bit[i]>0){
                    bit[i]--;
                }
                else{
                    while(i<30 && bit[i]==0){
                        i++;
                        count++;
                    }
                    bit[i]--;
                    continue;
                }
             
            }
            bit[i+1]+=(bit[i]/2);
            i++;
        }
        return count;
    }
};