class Solution {
public:
    vector<int> getRow(int r) {
        if(r==0) return {1};

        vector<vector<int>> dp(r+1);
        for(int i=0;i<=r;i++){
            dp[i]=vector<int>(i+1,1);
        }   

        for(int i=2;i<=r;i++){
            for(int j=1;j<(dp[i].size()-1);j++){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }
        }

        return dp[r];
    }
};