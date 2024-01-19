class Solution {
public:
    int n,m;
    int f(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(i==n) 
        return 0;

        if(j==m || i<0 ||j<0)
        return INT_MAX-100;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int l=grid[i][j]+f(i+1,j-1,grid,dp);
        int d=grid[i][j]+f(i+1,j,grid,dp);
        int r=grid[i][j]+f(i+1,j+1,grid,dp);

        return dp[i][j]=min({l,d,r});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int j=0;j<m;j++) dp[0][j]=matrix[0][j];

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int l=1e9,r=1e9;

                if(j-1 >= 0) l=dp[i-1][j-1];
                if(j+1 < m) r=dp[i-1][j+1];

                dp[i][j]=matrix[i][j]+min({dp[i-1][j],l,r});
            }
        }

        int mn=INT_MAX;
        for(int j=0;j<m;j++) mn=min(mn,dp[n-1][j]);

        return mn;
    }
};