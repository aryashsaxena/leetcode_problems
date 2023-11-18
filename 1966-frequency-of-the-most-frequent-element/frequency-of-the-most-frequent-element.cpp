class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();

        sort(nums.rbegin(),nums.rend());

        int mx=0,i=0,j=0,count=0;
        while(i<n){
            int x=nums[j]-nums[i];
            while(k<x){
                int y=nums[j]-nums[j+1];
                k+=(count)*y;
                j++;
                count--;
            }
            i++;
            count++;
            k-=x;
            mx=max(mx,count);
        }

        return mx;
    }
};