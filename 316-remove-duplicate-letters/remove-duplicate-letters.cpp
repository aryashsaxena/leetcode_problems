class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> m;
        unordered_set<char> st;
        stack<char> dq;

        for(int i=0;i<s.size();i++) m[s[i]]=i;

        int i=0;
        while(i<s.size()){
            if(dq.empty()){
                dq.push(s[i]);
                st.insert(s[i]);
            }
            else{
                if(!st.count(s[i])){
                    while(!dq.empty() && dq.top()>s[i] && m[dq.top()]>i){
                        st.erase(dq.top());
                        dq.pop();
                    }

                    dq.push(s[i]);
                    st.insert(s[i]);
                }
            }
            i++;
        }

        string ans="";
        while(!dq.empty()){
            ans=dq.top()+ans;
            dq.pop();
        }
        return ans;
    }
};