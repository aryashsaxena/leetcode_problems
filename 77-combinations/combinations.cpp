class Solution {
public:
    vector<vector<int>>ans;

    void f(int  i,int n,int k,vector<int> &v){
        if(i>n){
            if(v.size()==k){
                ans.push_back(v);
            }
            return;
        }
        if(v.size()==k){
            ans.push_back(v);
            return;
        }

        v.push_back(i);
        f(i+1,n,k,v);
        v.pop_back();

        f(i+1,n,k,v);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> v;     
        f(1,n,k,v);
        return ans;
    }
};