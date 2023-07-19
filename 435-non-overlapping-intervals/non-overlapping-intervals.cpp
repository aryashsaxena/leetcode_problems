class Solution {
public:
    bool check(int a,int b,int x,int y){
        if(b<=x || a>=y) return false;
        return true; 
    }

    long long f(int i,int j,vector<vector<int>>&intr,vector<vector<long long>>&dp){
        if(i>=intr.size() || j>=intr.size() ) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

       if(check(intr[j][0],intr[j][1],intr[i][0],intr[i][1])){
           return dp[i][j]=1+min(f(i+1,j,intr,dp),f(i+1,i,intr,dp));
       }
       else
       return dp[i][j]=f(i+1,i,intr,dp);
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intr) {
        sort(intr.begin(),intr.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });

        // vector<vector<long long>> dp(intr.size(),vector<long long>(intr.size(),-1));
        
        // return f(1,0,intr,dp);

        int ans=0;
        int prev=INT_MIN;
        for(auto i:intr){
            if(i[0]<prev) ans++;
            else prev=i[1];
        }
        return ans;
    }
};