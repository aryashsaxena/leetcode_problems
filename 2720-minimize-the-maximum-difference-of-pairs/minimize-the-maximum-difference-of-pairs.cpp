class Solution {
public:
    long long f(int i,int p,vector<int>&nums,vector<vector<long long>>&dp){
        if(i>=nums.size() && p!=0) return INT_MAX-100;
        if(i>=nums.size() || p==0) return 0;

        if(dp[i][p]!=-1) return dp[i][p];

        long long ntake=f(i+1,p,nums,dp);
        long long take=INT_MAX;
        if(i+1<nums.size()){
            take=max(1LL*abs(nums[i+1]-nums[i]),f(i+2,p-1,nums,dp));
        }
        return dp[i][p]=min(take,ntake);
    }

    long long check(long long x,vector<int>&nums,int p){
        long long count=0;
        int i=0;
        while(i<nums.size()-1){
            if(nums[i+1]-nums[i]<=x){
                count++;
                i+=2;
            }
            else i++;
        }
        return count;
    }

    int minimizeMax(vector<int>& nums, int p) {
        
        sort(nums.begin(),nums.end());
        // vector<vector<long long>>dp(nums.size()+1,vector<long long>(p+1,-1));

        // return f(0,p,nums,dp);

        int n=nums.size();

        // if(n==1) return 0;

        long long l=0,h=nums[n-1]-nums[0];
        long long ans=0;
        while(l<h){
            long long mid=(l+h)>>1;

            long long x=check(mid,nums,p);
            if(x>=p){
                ans=mid;
                h=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};