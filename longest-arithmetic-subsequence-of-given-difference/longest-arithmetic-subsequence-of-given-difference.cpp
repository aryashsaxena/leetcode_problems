class Solution {
public:
    int f(int i,int j,vector<int>&nums,int x,unordered_map<int,unordered_map<int,int>>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i].count(nums[i]-x)) return dp[i][j+1];

        int ntake=f(i+1,j,nums,x,dp);
        int take=0;
        if(j==-1 || nums[i]-nums[j]==x){
            take=1+f(i+1,i,nums,x,dp);
        }
        return dp[i][j+1]=max(take,ntake);
    }

    int longestSubsequence(vector<int>& nums, int x) {
        // unordered_map<int,unordered_map<int,int>> dp;
        // return f(0,-1,nums,x,dp);

        unordered_map<int,int> dp;
        int a=0,ans=0;
       for(int i=0;i<nums.size();i++){
           if(dp.count(nums[i]-x)){
               a=dp[nums[i]-x];
           }
           else a=0;

           dp[nums[i]]=a+1;
           ans=max(ans,dp[nums[i]]);
       }

        return ans;
    }
};