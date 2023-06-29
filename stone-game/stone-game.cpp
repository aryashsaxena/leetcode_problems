class Solution {
public:
    int n;

    int f(int i,int j,int x,vector<int>&nums,vector<vector<vector<int>>>&dp){
        if(i>=n || j<0 ) return 0;
        if(dp[i][j][x]!=-1) return dp[i][j][x];

        int take=0,ntake=0;
        if(x==0){
            take=nums[i]+f(i+1,j,1,nums,dp);
            ntake=nums[j]+f(i,j-1,1,nums,dp);
        }
        else{
            take=-nums[i]+f(i+1,j,0,nums,dp);
            ntake=-nums[j]+f(i,j-1,0,nums,dp);
        }

        // cout<<take<<" "<<ntake<<endl;
        return dp[i][j][x]= max(take,ntake);
    }

    bool stoneGame(vector<int>& piles) {
         n=piles.size();
       vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));

        int x=f(0,n-1,0,piles,dp) ;
        cout<<x<<endl;

        return x>0 ;
    }
};