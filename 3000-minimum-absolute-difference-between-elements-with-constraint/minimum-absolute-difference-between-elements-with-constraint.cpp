class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> st;
        int mn=INT_MAX;
        
        for(int i=x;i<nums.size();i++){
            st.insert(nums[i-x]);
            auto it=st.lower_bound(nums[i]);
            if(it!=st.end()){
                mn=min(mn,abs(*it-nums[i]));
            }
            
            if(it!=st.begin()){
                // it--;
                mn=min(mn,abs(*prev(it)-nums[i]));
            }
        }
        return mn;
    }
};