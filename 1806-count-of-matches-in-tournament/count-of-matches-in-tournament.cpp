class Solution {
public:
    int numberOfMatches(int n) {
        int count=0;

        while(n!=1){
            count+=(n/2);
            if(n&1){
                n=(n/2 + 1);
            }
            else n=n/2;
        }
        return count;
    }
};