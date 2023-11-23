class Solution {
public:
    bool f(vector<int> &nums,int l,int r){
        vector<int> v;

        for(int j=l;j<=r;j++) v.push_back(nums[j]);

            sort(v.begin(),v.end());
            
            int ch=0;
            if(v.size()==1){
                return true;
            }

            int d=v[1]-v[0];
            for(int j=1;j<v.size();j++){
                if((v[j]-v[j-1])!=d){
                    ch=1;
                    return false;
                }
            }

            return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;

        for(int i=0;i<l.size();i++){
            vector<int> v;
            ans.push_back(f(nums,l[i],r[i]));
        }   

        return ans;
    }
};