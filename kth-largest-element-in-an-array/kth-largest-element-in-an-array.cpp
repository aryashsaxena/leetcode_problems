class Solution {
public:
    int partition(int l,int h,vector<int>&nums){
        int i=l-1;
        int pivot=nums[h];

        for(;l<h;l++){
            if(nums[l]<=pivot){
                i++;
                swap(nums[l],nums[i]);
            }
        }

        i++;
        swap(nums[i],nums[h]);
        return i;
    }

    int quick(int l,int h,int k,vector<int>&nums){
        if(l>h) return 0;

        int p=partition(l,h,nums);

        if(p==k) return nums[p];
        if(p<k) return quick(p+1,h,k,nums);
        else return quick(l,p-1,k,nums);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int l=0,h=nums.size()-1;
        k=h-k+1;

        return quick(l,h,k,nums);
    }
};