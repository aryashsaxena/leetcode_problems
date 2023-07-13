class Solution {
public:

    bool f(int i,unordered_set<int>&vis,unordered_set<int>&rvis,unordered_map<int,vector<int>>&grid){
        vis.insert(i);
        rvis.insert(i);

        for(auto j:grid[i]){
            if(!vis.count(j)){
                if(f(j,vis,rvis,grid)) return true;
            }
             if(rvis.count(j)) return true;
        }

        rvis.erase(i);
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& grid) {

        unordered_map<int,vector<int>> adj;
        for(auto i:grid){
            adj[i[0]].push_back(i[1]);
        }

        unordered_set<int> vis,rvis;
        for(int i=0;i<numCourses;i++){
            if(!vis.count(i) && f(i,vis,rvis,adj)){
                return false;
            }
        }
        return true;
    }
};