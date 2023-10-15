class Solution {
public:
    const int mod=1e9+7;
    unordered_map<string,long long> mp;

    int f(int st,int len,int n){
        string s=to_string(st)+"->"+to_string(len);

        if(st==0 && len==0) return 1;
        if(len==n || len<0 || st<=0) return 0;
        if(mp.count(s)) return mp[s];

        long long count= (1LL*f(st-1,len+1,n)%mod + 1LL*f(st-1,len-1,n)%mod + 1LL*f(st-1,len,n)%mod )%mod;

        return mp[s]=count;
    }

    int numWays(int steps, int len) {
        // vector<vector<int>> dp(steps+1,vector<int>(len+1,-1));

        return f(steps,0,len);
    }
};