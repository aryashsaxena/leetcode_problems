class Solution {
public:
    string largestGoodInteger(string num) {
        string x="";
        for(int i=1;i<num.size()-1;i++){
            if(num[i]==num[i-1] && num[i]==num[i+1]){
               if(x.size()==0 || x[0]<num[i]){
                   x=num[i];
                   x+=num[i];
                   x+=num[i];
               }
            }
        }
        return x;
    }
};