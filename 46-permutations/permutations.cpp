class Solution {
public:
    vector<vector<int>> ans;

    void f(vector<int>&nums,vector<int>&vis,vector<int>&v){

         if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        } 

        for(int j=0;j<nums.size();j++){
            if(vis[j]) continue;

            vis[j]=1;
            v.push_back(nums[j]);
            f(nums,vis,v);
            v.pop_back();
            vis[j]=0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vis(nums.size(),0);
        vector<int> v;
        f(nums,vis,v);

        return ans;
    }
};