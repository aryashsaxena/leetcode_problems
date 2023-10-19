class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        for(auto i:s){
            if(i=='#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(i);
            }
        }

        string ans="",ans2="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }

        for(auto i:t){
            if(i=='#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(i);
            }
        }

        while(!st.empty()){
            ans2=st.top()+ans2;
            st.pop();
        }
        return ans==ans2;
    }
};