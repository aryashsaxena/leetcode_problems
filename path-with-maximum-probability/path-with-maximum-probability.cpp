class Solution {
public:

    // double f(int i,int n,vector<vector<pair<int,double>>>&adj,vector<int>&vis){
    //     if(i==n) return 1.00;

    //     double ans=0;
    //     vis[i]=1;
    //     for(auto j:adj[i]){
    //         if(vis[j.first]) continue;

    //         ans=max(ans,j.second * f(j.first,n,adj,vis));            
    //     }
    //     // vis[i]=0;
    //     return ans;
    // }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succ[i]});
            adj[edges[i][1]].push_back({edges[i][0],succ[i]});
        }

        // vector<int> vis(n,0);
        // return f(start,end,adj,vis);

        priority_queue<pair<double,int>> pq;
        pq.push({1,end});
        vector<double> dist(n,0);

        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();

            for(auto j:adj[p.second]){
                double x=p.first* j.second;

                if(dist[j.first]<x){
                    dist[j.first]=x;
                    pq.push({x,j.first});
                }
            }
        }

        return dist[start];
    }
};