//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class dsu{
  public:
  
  vector<int> parent,rank,size;
  
  dsu(int n){
      parent.resize(n+1,0);
      size.resize(n+1,1);
      
      for(int i=0;i<=n;i++) parent[i]=i;
  }
  
  int find(int i){
      if(parent[i]==i) return i;
      
      return parent[i]=find(parent[i]);
  }
  
  void uniion(int i,int j){
      int x=find(i);
      int y=find(j);
      
      if(x==y) return ;
      if(size[x]<=size[y]){
          parent[x]=y;
          size[y]+=size[x];
      }
      else{
          parent[y]=x;
          size[x]+=size[y];
      }
  }
};

class Solution
{
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        int n=grid.size();
        
        dsu ds(n*n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int node=i*n + j;
                    
                    for(int k=0;k<4;k++){
                        int x=i+dx[k];
                        int y=j+dy[k];
                        
                        int temp= x*n + y;
                        if((x>=0 && x<n && y>=0 && y<n) && grid[x][y]==1){
                            ds.uniion(node,temp);
                        }
                    }
                    
                }
            }
        }
        
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    
                    unordered_set<int> cmp;
                    
                    int node=i*n + j;
                    
                    for(int k=0;k<4;k++){
                        int x=i+dx[k];
                        int y=j+dy[k];
                        
                        int temp= x*n + y;
                        if(((x>=0 && x<n) && (y>=0 && y<n)) && grid[x][y]==1){
                            cmp.insert(ds.find(temp));
                        }
                    }
                    
                    int count=0;
                    for(auto it:cmp){
                        count+=ds.size[it];
                    }
                    
                    mx=max(mx,count + 1);
                }
            }
        }
        
        for(int i=0;i<(n*n);i++){
            mx=max(mx,ds.size[ds.find(i)]);
        }
        
        return mx;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends