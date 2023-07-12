class Solution {
public:
    
    bool f(int i,vector<int>&vis,vector<int>&rvis,vector<vector<int>>&adj){
        vis[i]=1;
        rvis[i]=1;

        for(auto j:adj[i]){
            if(!vis[j] && f(j,vis,rvis,adj)){
                return true;
            }
            if( rvis[j]) return true;
        }

        rvis[i]=0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       
       vector<int> vis(graph.size(),0),rvis(graph.size(),0);

       for(int i=0;i<vis.size();i++){
           if(!vis[i]){
               f(i,vis,rvis,graph);
           }
       }

       vector<int> ans;
       for(int i=0;i<rvis.size();i++){
           if(!rvis[i]) ans.push_back(i);
       }

       return ans;
    }
};