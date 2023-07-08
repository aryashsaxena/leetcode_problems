class Solution {
public:

    bool check(long long mid, int k,vector<int>&nums){
        long long sum=0;
        int count=1;

        for(auto i:nums){
            if(i>mid) return false;
            if(sum+i>mid){
                count++;
                sum=i;
            }
            else
            sum+=i;
        }
        // if(sum!=0) count++;

        return count<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long l=*max_element(nums.begin(),nums.end()),h=accumulate(nums.begin(),nums.end(),0LL);
        long long ans=0;

        while(l<=h){
            long long mid=(l+h)>>1;

            if(check(mid,k,nums)){
                // cout<<'a';
                // ans=max(ans,mid);
                ans=mid;
                h=mid-1;
            }
            else 
            l=mid+1;
        }
        return ans;
    }
};