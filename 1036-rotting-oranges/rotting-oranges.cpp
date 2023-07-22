class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

         int rotten=0;
     int fresh=0;

     int m=grid.size();
     int n=grid[0].size();
     queue<pair<int,int>>q;
   
                 
     for(int i=0;i<grid.size();i++)
     {
         for(int j=0;j<grid[0].size();j++)
         {
             if(grid[i][j]==1) fresh++;
             if(grid[i][j]==2) {
                 rotten++;
                 q.push({i,j});
             
             }
         }
     }
     if(fresh==0) return 0;
     

     int count=0;
         while(!q.empty())
                {
                    int sz=q.size();
                    for(int z=0;z<sz;z++)
                    {
                    int x=q.front().first;
                    int y=q.front().second;

                        if(x-1>=0 && grid[x-1][y]==1 ){

                        q.push({x-1,y});
                        grid[x-1][y]=2;
                        fresh--;
                        }
                        if(x+1<m && grid[x+1][y]==1){

                        q.push({x+1,y});
                        grid[x+1][y]=2;
                        fresh--;
                        }

                        if(y-1>=0 && grid[x][y-1]==1 ){

                        q.push({x,y-1});
                        grid[x][y-1]=2;
                        fresh--;
                         }
                        if(y+1<n && grid[x][y+1]==1)
                        {
                        q.push({x,y+1});
                        grid[x][y+1]=2;
                        fresh--;
                        }
                    q.pop();
                    }
                    if(!q.empty())
                    count++;

              }

     if(fresh==0) return count;
     return -1;


        
        // queue<pair<int,int>> q;
        // int tot=0;

        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[i].size();j++){
        //         if(grid[i][j]!=0) tot++;

        //         if(grid[i][j]==2){
        //             q.push({i,j});
        //         }
        //     }
        // }

        // int count=0,ans=0;
        // int x[4]={1,-1,0,0};
        // int y[4]={0,0,1,-1};

        // while(!q.empty()){
        //     int sz=q.size();
        //     count+=sz;

        //     while(sz--){
        //         auto t=q.front();
        //         q.pop();

        //         for(int k=0;k<4;k++){
        //             int i=t.first+x[k];
        //             int j=t.second+y[k];

        //             if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1) continue;

        //             grid[i][j]=2;
        //             q.push({i,j});
        //         }
        //     }
        //         if(!q.empty())
        //        ans++;
        // }
        
        // return count!=tot ? -1 : ans;
    }
};