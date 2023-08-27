class Solution {
public:
    unordered_map<int,int> m;
    int n;

    int f(int i,int k,vector<int>&nums,vector<vector<int>>&dp){
        if(i>=n-1) return true;
        if(dp[i][k]!=-1) return dp[i][k];

        if(m.count(nums[i]+k) && m[nums[i]+k]>i){
            if(f(m[nums[i]+k],k,nums,dp)) return dp[i][k]=true;
        }
        if(m.count(nums[i]+k-1) && m[nums[i]+k-1]>i){
            if(f(m[nums[i]+k-1],k-1,nums,dp)) return dp[i][k]=true;
        }
        if(m.count(nums[i]+k+1) && m[nums[i]+k+1]>i){
            if(f(m[nums[i]+k+1],k+1,nums,dp)) return dp[i][k]= true;
        }
        return dp[i][k]=false;
    }

    bool canCross(vector<int>& stones) {
        n=stones.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        for(int i=0;i<n;i++){
            m[stones[i]]=i;
        }
        return f(0,0,stones,dp);
    }
};