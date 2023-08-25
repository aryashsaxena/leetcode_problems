class Solution {
public:
    bool f(int i,int j,int k,string &s,string &t,string &tot,vector<vector<int>>&dp){
        if(k>=tot.size()){
            if(i>=s.size() && j>=t.size()) return true;
            return false;
        }
        if(i>=s.size()){
            while(j<t.size() && k<tot.size()){
                if(t[j]!=tot[k]) break;
                j++;
                k++;
            }
            if(j==t.size() && k==tot.size()) return true;
            return false;
        }
         if(j>=t.size()){
            while(i<s.size() && k<tot.size()){
                if(s[i]!=tot[k]) break;
                i++;
                k++;
            }
            if(i==s.size() && k==tot.size()) return true;
            return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        bool ans=false;
        if(s[i]==tot[k] && t[j]==tot[k]){
            ans=f(i+1,j,k+1,s,t,tot,dp)|f(i,j+1,k+1,s,t,tot,dp);
        }
        else if(s[i]==tot[k]){
            ans=f(i+1,j,k+1,s,t,tot,dp);
        }
        else if(t[j]==tot[k]){
            ans=f(i,j+1,k+1,s,t,tot,dp);
        }
        return dp[i][j]=ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return f(0,0,0,s1,s2,s3,dp);
        
        // string s="";
        // int i=0,k=0;

        // while(i<s3.size()){
        //     if(k<s2.size() && s2[k]==s3[i]){
        //         k++;
        //     }
        //     else s+=s3[i];
        //     i++;
        // }
        // cout<<s<<" ";
        // if(k==s2.size() && s==s1) return true;

        // k=0,s="";
        // i=0;
        // while(i<s3.size()){
        //     if(k<s1.size() && s1[k]==s3[i]){
        //         k++;
        //     }
        //     else s+=s3[i];
        //     i++;
        // }
        // cout<<s<<endl;
        // if(k==s1.size() && s==s2) return true;
        // return false;
    }
};