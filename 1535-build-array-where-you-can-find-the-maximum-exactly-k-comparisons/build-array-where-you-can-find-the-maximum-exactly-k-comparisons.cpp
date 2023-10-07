class Solution {
public:
    int mod=1e9+7;

    int f(int i,int cost,int mx,int n,int k,int m,vector<vector<vector<int>>>&dp){
        if(i>=n) return cost==k;
        if(cost>k) return 0;
        if(dp[i][cost][mx]!=-1) return dp[i][cost][mx];

        int count=0;
        for(int j=1;j<=m;j++){
            if(j>mx){
                count= (count%mod + f(i+1,cost+1,j,n,k,m,dp)%mod)%mod;
            }
            else{
                count= (count%mod + f(i+1,cost,mx,n,k,m,dp)%mod)%mod;
            }
        }
        return dp[i][cost][mx]=count%mod;
    }

    int numOfArrays(int n, int m, int k) {
        // if(m<k) return 0;
        
       vector<vector<vector<int>>> dp(n+100,vector<vector<int>>(k+100,vector<int>(m+100,-1)));
       return f(0,0,0,n,k,m,dp);
    }
};