class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;

        while(l<=h){
            int mid=(l+h)>>1;
            if(nums[mid]==target) return true;

            if(nums[mid]==nums[h] && nums[l]==nums[mid]){
                l++;
                h--;
            }
            else if(nums[l]<=nums[mid]){
                if(nums[l]<=target && nums[mid]>=target ){
                    h=mid-1;
                }
                else l=mid+1;
            } 
            else{
                if(nums[mid]<=target && nums[h]>=target ) 
                l=mid+1;
                else h=mid-1;
            }
        }
        return false;
    }
};