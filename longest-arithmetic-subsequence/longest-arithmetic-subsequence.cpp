class Solution {
public:
    unordered_map<int,unordered_map<int,int>> dp;

    int f(int i,int d,vector<int>&nums){
        if(i<0) return 0;
        if(dp[i].count(d)) return dp[i][d];

        int ans=0;
        for(int j=i-1;j>=0;j--){
            if(nums[i]-nums[j]==d){
                ans=max(ans,1+f(j,d,nums));
            }
        }
        return dp[i][d]=ans;
    }

    int longestArithSeqLength(vector<int>& nums) {

        vector<vector<int>> dp(nums.size()+1,vector<int>(1003,0));

        int ans=0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                int d=nums[i]-nums[j]+500;

                dp[i][d]=dp[j][d]>0 ? dp[j][d]+1 : 2;

                ans=max(ans,dp[i][d]);
            }
        }

        return ans;
        // if(nums.size()<=2) return nums.size();

        // int ans=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         int d=nums[j]-nums[i];

        //         ans=max(ans,2+f(i,d,nums));
        //     }
        // }
        // return ans;
    }
};