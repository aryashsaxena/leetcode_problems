class Solution {
public:

    // int f(int t,vector<int>&vis,vector<int>&cost,vector<int>&time,map<pair<vector<int>,int>,int> &dp){
    //     if(t>(cost.size()/2)) return 0;

    //     if(dp.count({vis,t})) return dp[{vis,t}];
    //         int count=INT_MAX;
    //         for(int i=0;i<cost.size();i++){
    //             if(!vis[i]){
    //                 vis[i]=1;

    //                 if(t==0)
    //                 count=min(count,cost[i]+f(t+time[i],vis,cost,time,dp));
    //                 else count=min(count,f(t-1,vis,cost,time,dp));

    //                 vis[i]=0;
    //             }
    //         }
    //     return dp[{vis,t}] = count==INT_MAX ? 0 : count;
    // }

    int f(int i,int t,vector<vector<int>>&nums,vector<vector<int>>&dp){
        if(t>=(nums.size())) return 0;
        if(i>=nums.size()) return 1e9;
        if(dp[i][t]!=-1) return dp[i][t];

        

        int take=nums[i][0]+f(i+1,t+nums[i][1]+1,nums,dp);
        // if(t>0){
            take=min(take,f(i+1,t,nums,dp));
        // }
        return dp[i][t]=take;
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
    //     vector<int> vis(cost.size(),0);
    //     map<pair<vector<int>,int>,int> dp;

    //    return f(0,vis,cost,time,dp); 

        vector<vector<int>> nums;
        for(int i=0;i<cost.size();i++){
            nums.push_back({cost[i],time[i]});
        }

        sort(nums.rbegin(),nums.rend());

        vector<vector<int>> dp(nums.size()+1,vector<int>(1001,-1));

        return f(0,0,nums,dp);
    }
};