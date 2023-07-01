class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        unordered_map<int,int> Or;
        unordered_map<int,int> oc,zr,zc;
        int n=grid.size() ,m=grid[0].size();

        for(int i=0;i<n;i++){
            int z=0,o=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) o++;
                else z++;
            }

            Or[i]=o;
            zr[i]=z;
        } 

         for(int j=0;j<m;j++){
            int z=0,o=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==1) o++;
                else z++;
            }

            oc[j]=o;
            zc[j]=z;
        } 

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=Or[i]+oc[j]-zr[i]-zc[j];
            }
        }

        return grid;
    }
};