class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        vector<int> row(n),col(m);
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) count++;
            }

            row[i]=count;
        }

         for(int j=0;j<m;j++){
            int count=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==1) count++;
            }

            col[j]=count;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=row[i]+col[j]-(n-row[i])-(m-col[j]);
            }
        }

        return grid;
    }
};