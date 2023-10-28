class Solution {
public:
    long long mod=1e9+7;

    map<pair<int,char>,long long> dp;
    int f(int n,char ch){
        if(n<=0) return 1;
        if(dp.count({n,ch})) return dp[{n,ch}];

        long long ans=0;
        if(ch=='a'){
            ans+=f(n-1,'e')%mod;
        }
        if(ch=='e' ){
            ans+=(f(n-1,'a')%mod+f(n-1,'i')%mod)%mod;
        }
        if(ch=='i'){
            ans+=(f(n-1,'a')%mod + f(n-1,'e')%mod + f(n-1,'o')%mod + f(n-1,'u')%mod)%mod;
        }
        if(ch=='o'){
            ans+=f(n-1,'i')+f(n-1,'u')%mod;
        }
        if(ch=='u') ans+=f(n-1,'a')%mod;

        if(ch=='#'){
            // cout<<"arua";
            ans=(f(n-1,'a')%mod+f(n-1,'e')%mod+f(n-1,'o')%mod+f(n-1,'u')%mod+f(n-1,'i')%mod)%mod;
        }
        return dp[{n,ch}]=ans%mod;
    }

    int countVowelPermutation(int n) {
        return f(n,'#')%mod;
    }
};