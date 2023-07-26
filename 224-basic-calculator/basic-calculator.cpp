class Solution {
public:
    int calculate(string s) {
        int ans=0;
        stack<int> st;
        int num=0,sign=1;

        for(auto ch:s){
            if(isdigit(ch)){
                num=num*10+(ch-'0');
            }
            else if(ch=='+'){
                ans+=num*sign;
                num=0;
                sign=1;
            }
            else if(ch=='-'){
                ans+=num*sign;
                num=0;
                sign=-1;
            }
            else if(ch=='('){
                st.push(ans);
                st.push(sign);

                ans=0;
                sign=1;
            }
            else if(ch==')'){
                ans+=num*sign;
                ans=ans*st.top();
                st.pop();

                ans+=st.top();
                st.pop();
                num=0;
            }
        }
        ans+=num*sign;
        return ans;
    }
};