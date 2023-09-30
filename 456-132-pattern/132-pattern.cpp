class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int mx=INT_MIN;
        int fl=0;

        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<mx) return true;
            else{
                while(!st.empty() && nums[i]>st.top()){
                  mx=st.top();
                  st.pop();
                  fl=1;
                }
            }
            st.push(nums[i]);
        }
      if(fl==1 && mx>nums[0]) return true;
      return false;
    }
};