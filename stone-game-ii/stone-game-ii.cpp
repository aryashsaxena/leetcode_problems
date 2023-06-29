class Solution {
public:
    int n;

    int f(int i,int m,int fg,vector<int>&nums,vector<vector<vector<int>>>&dp){
        if(i>=n) return 0;
        if(dp[i][m][fg]!=-1) return dp[i][m][fg];

        int ans= fg==0 ? 0 : INT_MAX-1000;
        if(fg==0){
            int sum=0;
            for(int x=1;x<=2*m;x++){
                if(i+x-1>=n) break;

                sum+=nums[i+x-1];
                ans=max(ans,sum + f(i+x,max(m,x),1,nums,dp));
            }
        }
        else{
             for(int x=1;x<=2*m;x++){
                if(i+x-1>=n) break;

                ans=min(ans,f(i+x,max(m,x),0,nums,dp));
            }
        }

        return dp[i][m][fg]=ans;
    }

    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        return f(0,1,0,piles,dp);
    }
};