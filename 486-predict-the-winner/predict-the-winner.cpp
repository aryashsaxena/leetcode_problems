class Solution {
public:
    int f(int i,int j,int ch,vector<int>&nums,vector<vector<vector<int>>>&dp){
        if(i>=nums.size() || j<0 || i>j) return 0;
        if(dp[i][j][ch]!=-1) return dp[i][j][ch];

        if(i==j){
            return ch==0? nums[i] : -nums[i];
        }

        if(ch==0){
            return dp[i][j][ch]=max(nums[i]+f(i+1,j,1,nums,dp),nums[j]+f(i,j-1,1,nums,dp));
        }
        else{
            return dp[i][j][ch]=min(-nums[i]+f(i+1,j,0,nums,dp),-nums[j]+f(i,j-1,0,nums,dp));
        }
    }

    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size()+1,vector<vector<int>>(nums.size()+1,vector<int>(2,-1)));
        int x=f(0,nums.size()-1,0,nums,dp);
        cout<<x<<" ";
        return x>=0 ? true : false;
    }
};