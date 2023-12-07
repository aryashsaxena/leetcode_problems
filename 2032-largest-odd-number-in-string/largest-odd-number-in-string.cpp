class Solution {
public:
    string largestOddNumber(string num) {
        
        // string ans="";
        int j=num.size()-1;

        while(num.size()!=0){
            int x=num[num.size()-1]-'0';

            if(x%2!=0)
            return num;
            else
            num.pop_back();
        }
        return "";
    }
};