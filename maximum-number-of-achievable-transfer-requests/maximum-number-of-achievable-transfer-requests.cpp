class Solution {
public:
    int ans=0;

    void f(int i,int x,vector<int>&v,vector<vector<int>>&nums){
        if(i==nums.size()){
            for(int j=0;j<v.size();j++){
                if(v[j]!=0) return ;
            }

            ans=max(ans,x);
            return;
        }

        int from=nums[i][0];
        int to=nums[i][1];

        v[from]--;
        v[to]++;

        f(i+1,x+1,v,nums);

        v[from]++;
        v[to]--;
        f(i+1,x,v,nums);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        vector<int> v(n);
        f(0,0,v,requests);
        return ans;
    }
};