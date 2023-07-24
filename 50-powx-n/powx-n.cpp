class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long long int nn=n;

        if(nn<0) nn=-nn;

        while(nn){
            if(nn&1){
                ans=ans*x;
                nn--;
            }
            else{
                x*=x;
                nn/=2;
            }
        }

        if(n<0){
            ans=1.0/ans;
        }
        return ans;
    }
};