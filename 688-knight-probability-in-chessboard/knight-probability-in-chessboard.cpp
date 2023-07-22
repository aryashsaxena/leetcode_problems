class Solution {
public:
    double f(int i,int j,int k,int n,vector<vector<vector<double>>>&dp){
        if(i<0 || i>=n || j<0 || j>=n) return 0;
        if(k==0) return 1;

        if(dp[i][j][k]!=-1) return dp[i][j][k];

        double ans=0;
        vector<pair<int,int>> v={{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};

        for(auto x:v){
            ans+=f(i+x.first,j+x.second,k-1,n,dp);
        }
        return dp[i][j][k]=(double)(ans/8);
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));

        return f(row,column,k,n,dp);
    }
};