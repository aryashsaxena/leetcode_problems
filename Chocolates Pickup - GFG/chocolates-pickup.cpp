//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j){
                    dp[n-1][i][j]=grid[n-1][j];
                }
                else dp[n-1][i][j]=grid[n-1][i]+grid[n-1][j];
            }
        }
        
        int dy[3]={-1,0,1};
        
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int mx=-1e8;
                    
                    for(int k1=0;k1<3;k1++){
                        int y1=j1+dy[k1];
                        
                        for(int k2=0;k2<3;k2++){
                            int y2=j2+dy[k2];
                            
                            if(y1<0 || y1>=m || y2<0 || y2 >=m) continue;
                            
                            mx=max(mx,dp[i+1][y1][y2]);
                        }
                    }
                    
                    if(j1==j2) dp[i][j1][j2]=mx+grid[i][j1];
                    else dp[i][j1][j2]=mx+grid[i][j1]+grid[i][j2];
                }
            }
        }
        
        return dp[0][0][m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends