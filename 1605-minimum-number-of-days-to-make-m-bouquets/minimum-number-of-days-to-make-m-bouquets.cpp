class Solution {
public:
    int get(vector<int>&nums,int mid,int m,int k){
        int sum=0;
        int count=0;
        
        for(auto i:nums){
            if(i<=mid)sum++;
            else if(i>mid){
                if(sum==k) count++;
                sum=0;
                continue;
            }
            
            if(sum==k){
                count++;
                sum=0;
            }
        }
        return count;
    }
    int minDays(vector<int>& days, int m, int k) {
        if(1LL*m*k>days.size()) return -1;

        int l=*min_element(days.begin(),days.end());
        int h=*max_element(days.begin(),days.end());
        int ans=-1;

        while(l<=h){
            int mid=(l+h)>>1;

            int x=get(days,mid,m,k);

            if(x<m){
                l=mid+1;
            }
            else{
                ans=mid;
                h=mid-1;
            }
        }
        return ans;
    }
};