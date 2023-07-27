class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int rep) {
        int ex=count(s.begin(),s.end(),letter)-rep;
        int x=s.size()-k;
        string t="",ans="";

        for(auto ch:s){
            while(t.size()!=0 && t.back()>ch && x){
                if(t.back()==letter && ex==0) break;

                if(t.back()==letter) ex--;
                x--;
                t.pop_back();
            }

            t+=ch;
        }

        cout<<t<<" ";
        for(int i=0;ans.size()<k;i++){
            if(t[i]!=letter && ans.size()+max(0,rep)>=k) continue;
            
            ans+=t[i];
            if(t[i]==letter) rep--;
        }

        return ans;
    }
};