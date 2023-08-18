class Solution {
public:
    vector<vector<int>> ans;

    void f(int i,int sum,int n,int k,vector<int>&v){
         if(sum==n ){
            if(v.size()==k)
            ans.push_back(v);
            return;
        }
        if(i>=10 || sum>n || v.size()>k) return;

        v.push_back(i);
        f(i+1,sum+i,n,k,v);
        v.pop_back();

        f(i+1,sum,n,k,v);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        f(1,0,n,k,v);
        return ans;
    }
};