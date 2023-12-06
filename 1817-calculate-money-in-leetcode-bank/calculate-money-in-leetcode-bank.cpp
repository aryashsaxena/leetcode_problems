class Solution {
public:
    int totalMoney(int n) {
        int count=0;
        int x=1;
        int c=1;
        int d=0;
        while(n--){
            if(d==7){
                x++;
                c=x;
                d=0;
            }
            count+=c;
            c++;
            d++;
        }

        return count;
    }
};