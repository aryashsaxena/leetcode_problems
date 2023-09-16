class Solution {
public:
    int n,m;
    long long mod=1e9+7;

    long long f(int x,int y,vector<vector<int>>&grid,vector<vector<long long>>&dp,vector<vector<int>>&vis){
        
        if(x==n-1 && y==m-1) return 0;
        if(dp[x][y]!=-1) return dp[x][y];

        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};

        vis[x][y]=1;
        long long ans=INT_MAX;
        for(int k=0;k<4;k++){
            int i=x+dx[k],j=y+dy[k];
            if(i<0 || j<0 || i>=n || j>=m || vis[i][j]) continue;

            ans=min(ans, max(abs(grid[x][y]- grid[i][j])%mod , f(i,j,grid,dp,vis)%mod));
        }
        ans= ans==INT_MAX ? 0: ans;
        return dp[x][y]=ans%mod;
    }

    int minimumEffortPath(vector<vector<int>>& hgt) {
        n=hgt.size(),m=hgt[0].size();

        vector<vector<int>> vis(n,vector<int>(m,INT_MAX));
        // vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));
        
        queue<vector<long long>> q;
        q.push({0,0});
        vis[0][0]=0;

        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};

        long long ans=INT_MAX;
        while(!q.empty()){

                auto it=q.front();
                q.pop();

                for(int k=0;k<4;k++){
                    int i=it[0]+dx[k],j=it[1]+dy[k];

                    if(i<0 || j<0 || i>=n || j>=m) continue;
                    if(vis[i][j] <= vis[it[0]][it[1]]) continue;
                    
                    long long x=0;
                    x=max(1LL*vis[it[0]][it[1]] ,abs(hgt[it[0]][it[1]]- hgt[i][j])%mod);
                    q.push({i,j});
                    vis[i][j]=min(1LL*vis[i][j],x);   
                }

        }
        return vis[n-1][m-1];
    }
};