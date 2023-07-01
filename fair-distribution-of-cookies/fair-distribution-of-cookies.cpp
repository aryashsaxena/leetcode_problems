class Solution {
public:
    int ans=INT_MAX;

    void f(int i,vector<int>&nums,vector<int>&vis){
        if(i>=nums.size()){
            ans=min(ans,*max_element(vis.begin(),vis.end()));
            return ;
        }

        for(int k=0;k<vis.size();k++){
            vis[k]+=nums[i];
            f(i+1,nums,vis);
            vis[k]-=nums[i];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> vis(k,0);

        f(0,cookies,vis);
        return ans;
    }
};