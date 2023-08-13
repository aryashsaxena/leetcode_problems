class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size()) return true;
        if(dp[i]!=-1) return dp[i];
        
        bool check1=false,check2=false,check3=false;
        if(i+1<nums.size() && nums[i]==nums[i+1]){
            check1=f(i+2,nums,dp);            
        }
        if(i+2<nums.size()){
            if(nums[i+1]==nums[i] && nums[i+1]==nums[i+2]){
                check2=f(i+3,nums,dp);
            }
            if(nums[i+1]-nums[i]==1  && nums[i+2]-nums[i+1]==1){
                check3=f(i+3,nums,dp);
            }
        }
        return dp[i]=check1||check2||check3;
    }

    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return f(0,nums,dp);
    }
};