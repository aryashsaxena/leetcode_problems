class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()==1) return true;

        int fl=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                if(fl==-1) fl=1;
                else if(fl==0) return false;
            }
            else if(nums[i-1]>nums[i]){
                if(fl==-1) fl=0;
                else if(fl==1) return false;
            }
        }
        return true;
    }
};