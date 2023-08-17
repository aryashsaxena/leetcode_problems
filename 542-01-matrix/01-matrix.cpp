class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dp(mat.size(),vector<int>(mat[0].size(),0));
        queue<vector<int>> q;

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    mat[i][j]=2;
                }
            }
        }
        
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        while(!q.empty()){
            auto v=q.front();
            q.pop();

            dp[v[0]][v[1]]=v[2];

            for(int k=0;k<4;k++){
                int i=v[0]+dx[k],j=v[1]+dy[k];

                if(i>=0 && j>=0 && i<mat.size() && j<mat[0].size() && mat[i][j]==1){
                    q.push({i,j,v[2]+1});
                    mat[i][j]=2;
                }
            }            
        }
        
        return dp;
    }
};