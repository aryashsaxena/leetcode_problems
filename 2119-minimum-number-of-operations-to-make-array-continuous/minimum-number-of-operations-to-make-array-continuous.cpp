class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        vector<int> v;
        unordered_set<int> st;
        for(auto i:nums){
            if(!st.count(i)){
                v.push_back(i);
                st.insert(i);
            }
        }

        int mn=INT_MAX;
        for(int i=0;i<v.size();i++){
            int l=v[i];
            int r=l+n-1;

            int j=upper_bound(v.begin(),v.end(),r)-v.begin();
            mn=min(mn,n-(j-i));
        }
        return mn;
    }
};