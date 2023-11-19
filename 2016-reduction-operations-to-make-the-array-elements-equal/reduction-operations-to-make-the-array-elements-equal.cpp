class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        unordered_set<int> st;
        for(auto i:nums) st.insert(i);

        vector<int> v;
        for(auto i:st) v.push_back(i);

        sort(v.begin(),v.end());
        sort(nums.begin(),nums.end());
        int j=v.size()-1;

        int count=0;
        int n=nums.size(),i=n-1;
        while(i>=0){
            if(nums[i]==v[j]) j--;
            if(j<0) break;
            
            while(i>0 && nums[i]==nums[i-1]) i--;
            count+=(n-i);

            i--;
        }  
        return count;
    }
};