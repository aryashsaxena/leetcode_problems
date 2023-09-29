//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int n,m,ans=0;
    
    void f(int i,int j,vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=n || j>=m) return ;
        if(grid[i][j]==0) return ;
        
        grid[i][j]=0;
        f(i-1,j,grid);
        f(i+1,j,grid) ;
        f(i,j-1,grid) ;
        f(i,j+1,grid);
        
      
        return ;
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        n=grid.size(),m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                f(i,0,grid);
            }
            if(grid[i][m-1]==1) f(i,m-1,grid);
        }
        
        for(int j=0;j<m;j++){
            if(grid[0][j]==1) f(0,j,grid);
            if(grid[n-1][j]==1) f(n-1,j,grid);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends