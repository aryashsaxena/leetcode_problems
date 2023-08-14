class Solution {
public:
    int part(int l,int h,int k,vector<int>&nums){
        int pivot=nums[h];
        int i=l-1;
        for(int j=l;j<h;j++){
            if(nums[j]<=pivot){
                i++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1],nums[h]);
        return i+1;
    }

    int quicksort(int l,int h,int k,vector<int>&nums){
        if(l>h) return 0;

        int p=part(l,h,k,nums);
        if(p==k) return nums[p];
        if(p>k){
            return quicksort(l,p-1,k,nums);
        }
        else return quicksort(p+1,h,k,nums);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int l=0,h=nums.size()-1;
        k=h-k+1;

        return quicksort(l,h,k,nums);
    }
};