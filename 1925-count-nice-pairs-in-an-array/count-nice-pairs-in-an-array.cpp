class Solution {
public:
    int rev(int x){
        int ans=0;

        while(x){
            ans=ans*10 + (x%10);
            x/=10;
        }
        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> m;
        const int mod=1e9+7;

        long long ans=0;
        for(auto i:nums){
            int x=rev(i);
            
            if(m.count(i-x)){
                ans=(ans%mod + m[i-x]%mod)%mod;
            }
            m[i-x]++;
        }

        return ans%mod;
    }
};