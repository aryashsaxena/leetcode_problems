class Solution {
public:
    bool get(vector<int>&nums,vector<int>&heat,int r){
        int i=0,j=0;

        while(i<nums.size()){
            if(j==heat.size()){
                return false;
            }

            int low=heat[j]-r,high=heat[j]+r;

            if(nums[i]<low || nums[i]>high) j++;
            else i++;
        }
        return true;
    }

    int findRadius(vector<int>& nums, vector<int>& heat) {
        sort(nums.begin(),nums.end());
        sort(heat.begin(),heat.end());

        int l=0,h=max(nums[nums.size()-1],heat[heat.size()-1]);
        int ans=-1;

        while(l<=h){
            int mid=(l+h)>>1;

            if(get(nums,heat,mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};