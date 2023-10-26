class Solution {
public:
    unordered_map<long long,long long> dp;
    unordered_set<int> st;
    const int mod=1e9+7;

    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(auto i:arr){
            dp[i]=1;
            st.insert(i);
        }
        
        int count=0;
        for(auto i:arr){
            for(auto j:arr){
                if(j>sqrt(i)) break;

                if(st.count(i/j) && i%j==0){
                    long long x=1LL*dp[j]*dp[i/j];
                    if(i/j == j){
                        dp[i]=(dp[i]+x)%mod;
                    }
                    else dp[i]=(dp[i]+ x*2 )%mod;
                }
            }

            count=(count%mod + dp[i]%mod)%mod;
        }
        return count;
    }
};