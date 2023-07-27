class Solution {
public:
    long long maxRunTime(int n, vector<int>& batt) {
        sort(batt.begin(),batt.end());
        long long l=1;
        long long h=accumulate(batt.begin(),batt.end(),0LL);
        h/=n;
        long long ans=0;

        while(l<=h){
            long long mid=(l+h)>>1;

            long long x=0;
            for(auto i:batt) x+=min(1LL*i , mid);

            if((x/n)<mid){
                h=mid-1;
            }
            else{
                ans=mid;
                l=mid+1;
            }
        }
        return ans;
    }
};