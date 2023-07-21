class Solution {
public:
    // map<int,int>m;

    // int f(int i,int j,int count,vector<int>&nums){
    //     if(i>=nums.size()){
    //          m[count]++;
    //          return 0;
    //     }   
    //     if(dp[i].count(j)) return dp[i][j];

    //     int ans=f(i+1,j,count,nums);
    //     if(j==-1 || nums[j]<nums[i]){
    //        ans=max(ans, f(i+1,i,count+1,nums));
    //     }
    //     return dp[i][j]=ans;
    // }

    int findNumberOfLIS(vector<int>& nums) {
        // vector<int> dp(nums.size()+1,-1);
        //  return f(0,nums,dp);

        // for(auto i:m){
        //     cout<<i.first<<" "<<i.second<<" % ";
        // }
        // auto it=m.end();
        // it--;
        // return it->second;

        vector<int>dp(nums.size(),1),count(nums.size(),1);
        int mx=1;

        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && (1+dp[j])>dp[i]){
                    dp[i]=1+dp[j];
                    count[i]=count[j];
                }
                else if(nums[j]<nums[i] && (1+dp[j]==dp[i])){
                    count[i]+=count[j];
                }
            }
            mx=max(mx,dp[i]);
        }
        int ans=0;

        for(int i=0;i<nums.size();i++){
            if(mx==dp[i]) ans+=count[i];
        }
        return ans;
    }
};