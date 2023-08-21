//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int get(int i,int j,vector<vector<int>>&grid){
        int dx[8]={-1,-1,-1,1,1,1,0,0};
        int dy[8]={-1,0,1,-1,0,1,-1,1};
        int count=0;
        
        for(int k=0;k<8;k++){
            int x=i+dx[k],y=j+dy[k];
            
            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()) continue;
            if(grid[x][y]==0) count++;
        }
        return count==0 ? 1: count;
    }
    
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n=matrix.size(),m=matrix[0].size();
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    if((get(i,j,matrix))%2==0) count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends