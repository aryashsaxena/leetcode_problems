class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        long long t=sum-x;

        if(sum<x) return -1;
        if(sum==x) return nums.size();

        int mn=INT_MAX;
        int i=0,j=0;
        long long prf=0;

        while(i<nums.size()){
            prf+=nums[i];
            while(prf>t){
                prf-=nums[j];
                j++;
            }

            if(prf==t){
                int x=nums.size()-(i-j+1);
                mn=min(mn,x);
            }
            i++;
        }
        return mn==INT_MAX ? -1 : mn;
    }
};