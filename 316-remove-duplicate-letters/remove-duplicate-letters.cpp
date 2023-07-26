class Solution {
public:
    string removeDuplicateLetters(string s) {
        deque<char> dq;
        unordered_set<char> st;
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++) m[s[i]]=i;

        int i=0;

        while(i<s.size()){
            if(dq.empty()){
                dq.push_back(s[i]);
                st.insert(s[i]);
            }
            else{
                if(!st.count(s[i])){
                     while(!dq.empty() && dq.back()>s[i] && m[dq.back()]>i){
                         st.erase(dq.back());
                        dq.pop_back();
                    }
                    st.insert(s[i]);
                    dq.push_back(s[i]);
                }
            }
            i++;
        }

        string ans="";
        while(!dq.empty()){
            ans+=dq.front();
            dq.pop_front();
        }

        string x="";
        // for(auto i:m){
        //     if(i.second==1 && ans.find(i.first)>=ans.size()) x+=i.first;
        // }
        // sort(x.begin(),x.end());
        return x+ans;
    }
};