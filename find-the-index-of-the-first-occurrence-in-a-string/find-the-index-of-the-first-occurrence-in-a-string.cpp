class Solution {
public:
    int strStr(string s, string t) {
        
        int prv=0,j=1;
        vector<int> kmp(t.size(),0);

        while(j<t.size()){
            if(t[prv]==t[j]){
                kmp[j]=prv+1;
                j++;
                prv++;
            }
            else{
                if(prv==0){
                    kmp[j]=0;
                    j++;
                }
                else{
                    prv=kmp[prv-1];
                }
            }
        }

        int i=0;
        j=0;

        while(i<s.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                if(j==0) i++;
                else
                j=kmp[j-1];
            }
            if(j==t.size()){
                return i-t.size();
            }
        }
        return -1;
    }
};