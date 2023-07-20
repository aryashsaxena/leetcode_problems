class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        int i=0;

        while(i<nums.size()){
            if(st.empty()) st.push(nums[i]);
            else{
                if(nums[i]<0 && st.top()>0){
                    if(abs(st.top())<abs(nums[i])){
                        st.pop();
                        st.push(nums[i]);
                    }
                    else if(abs(st.top())==abs(nums[i])) st.pop();
                }
               else st.push(nums[i]);

               while(!st.empty() && st.size()>1){
                    int x=st.top();
                    st.pop();
                    if(x<0 && st.top()>0){
                        if(abs(x)>abs(st.top())){
                            st.pop();
                            st.push(x);
                        }
                        else if(abs(x)==abs(st.top())) st.pop();
                    }
                    else{
                        st.push(x);
                        break;
                    }
               }
            }
            i++;
        }

        i=st.size()-1;
        vector<int> ans(st.size());
        while(!st.empty()){
            ans[i--]=st.top();
            st.pop();
        }
        return ans;
    }
};