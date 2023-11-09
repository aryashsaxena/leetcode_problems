class Solution {
public:
    int countHomogenous(string s) {
        int count=0;
        const int mod=1e9+7;
        long long ans=0;

        char ch='#';

        for(auto i:s){
            if(ch==i){
                count++;
            }
            else{
                ans=((ans%mod)+(1LL*count*(count+1)/2)%mod)%mod;
                ch=i;
                count=1;
            }
        }

        ans=((ans%mod)+(1LL*count*(count+1)/2)%mod)%mod;
                
        return ans;
    }
};