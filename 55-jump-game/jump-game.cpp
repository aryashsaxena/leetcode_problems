class Solution {
public:
    
    bool f(int idx,int dis,vector<int> &nums,vector<bool> &dp)
    {
        if(idx==nums.size()-1) return true;
        
        if(dis==0) return false;
        
        if(dp[idx]!= true) return false;
        
        for(int i=1;i<=dis;i++)
        {
            bool check=f(idx+i,nums[idx+i],nums,dp);
            if(check) return dp[idx]= true;
        }
        
        return dp[idx]=false;
    }
    
    bool canJump(vector<int>& nums) {
        
        if(nums.size()==1) 
            return true;
    
        int n=nums.size();
        vector<bool> dp(n+1,true);

        return f(0,nums[0],nums,dp);

    //     vector<bool> dp(n,false);
        
    //     dp[n-1]=true;
    //     for(int idx=n-2;idx>=0;idx--)
    //     {
    //         int dis=nums[idx];
    //         bool ans=false;
    //         for(int j=1;j<=dis;j++)
    //         {
    //             if(idx+j<n)
    //                 ans=ans||dp[idx+j];
    //             else
    //                 break;
    //         }
    //         dp[idx]=ans;
            
    //     }
    //     return dp[0];
    //  // return  f(0,nums[0],nums,dp);
        
    }
};