class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0;
        int one=0;
        int mx=0;

        while(j<nums.size()){
           if(nums[j]==0) one++;

           if(one>1){
               mx=max(mx,j-i-1);
               while(i<=j && nums[i]!=0) i++;

               if(nums[i]==0) i++;
               one=1;
           }
           j++;
        }

        // if(one==0) mx=max(mx,j-i);
        if(one<=1) mx=max(mx,j-i-1);
        return mx;
    }
};