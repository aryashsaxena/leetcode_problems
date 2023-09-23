class Solution {
public:
    int f(int i,int j,vector<string>&word,vector<vector<int>>&dp){
        if(i>=word.size()) return 0;
        if(dp[i][j+1]!=-1) return dp[i][j+1];

        int take=0,ntake=0;
        if(j!=-1 && word[i].size()==(1+word[j].size())){
            int a=0,b=0,c=0;
            while(a<word[i].size() && b<word[j].size()){
                if(word[i][a]==word[j][b]){
                    a++;
                    b++;
                }
                else{
                    c++;
                    a++;
                }
            }
            if(c<=1){
                take=1+f(i+1,i,word,dp);
            }
        }
       else if(j==-1) take=1+f(i+1,i,word,dp);

        ntake=0+f(i+1,j,word,dp);
        return dp[i][j+1]=max(take,ntake);
    }

    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),[](auto &a,auto &b){
            return a.size()<b.size();
        });

        for(auto i:words) cout<<i<<" ";
        vector<vector<int>> dp(words.size()+1,vector<int>(words.size()+1,-1));
        return f(0,-1,words,dp);
    }
};