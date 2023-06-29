class Solution {
public:
    int n;

    int f(int i,int x,vector<int>&nums,vector<vector<int>>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i][x]!=-1) return dp[i][x];

        int ans= x==0 ? INT_MIN+1000 : INT_MAX-1000;
        if(x==0){
            int sum=0;
            for(int j=1;j<=3;j++){
                if(i+j-1>=n) break;

                sum+=nums[i+j-1];
                ans=max(ans,sum+f(i+j,1,nums,dp));
            }
        }
        else{
            int sum=0;
            for(int j=1;j<=3;j++){
                if(i+j-1>=n) break;

                sum-=nums[i+j-1];
                ans=min(ans,sum+f(i+j,0,nums,dp));
            }
        }

        // cout<<ans<<" ";
        return dp[i][x]=ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();

        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        int x=f(0,0,stoneValue,dp);
        // cout<<endl<<x;

        if(x>0) return "Alice";
        else if(x<0) return "Bob";
        return "Tie";
    }
};