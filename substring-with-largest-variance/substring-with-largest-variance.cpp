class Solution {
public:
    int largestVariance(string s) {
        int ans=0;

        unordered_set<char> st;
        for(auto ch:s) st.insert(ch);

        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j) continue;

                char c1=i+'a',c2=j+'a';
                int flag=0;
                if(!st.count(c1) || !st.count(c2)) continue;

                int f1=0,f2=0;
                for(auto ch:s)
                {
                    if(ch==c1) f1++;
                    if(ch==c2) f2++;

                    if(f1-f2<0){
                        f1=0,f2=0;
                        flag=1;
                    }

                    if(f2>0)
                    ans=max(ans,f1-f2);
                    else if(flag){
                        ans=max(ans,f1-1);
                    }
                }
            }
        }

        return ans;
    }
};