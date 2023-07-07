class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int i=0,j=0;
        int mx=0,count=0;
        int K=k;

        while(j<s.size()){
            if(s[j]=='F') count++;
            if(count>k){
                while(count>k && i<s.size()){
                    if(s[i]=='F') count--;
                    i++;
                }
            }
            mx=max(mx,j-i+1);
            j++;
        }

        count=0,j=0,i=0;
        while(j<s.size()){
            if(s[j]=='T') count++;
            if(count>k){
                while(count>k && i<s.size()){
                    if(s[i]=='T') count--;
                    i++;
                }
            }
            mx=max(mx,j-i+1);
            j++;
        }

        return mx;
    }
};