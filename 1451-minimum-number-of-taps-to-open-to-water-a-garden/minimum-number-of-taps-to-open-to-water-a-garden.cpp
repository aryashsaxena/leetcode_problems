class Solution {
public:
    int minTaps(int n, vector<int>& nums) {
        vector<long long>dp(n+1,INT_MAX);

        dp[0]=0;
        for(int i=0;i<=n;i++){
            int mn=max(0,i-nums[i]);
            int mx=min(n,i+nums[i]);

            for(int j=mn;j<=mx;j++){
                dp[mx]=min(dp[mx],dp[j]+1);
            }
        }
        return dp[n]==INT_MAX? -1 :  dp[n];
    }
};