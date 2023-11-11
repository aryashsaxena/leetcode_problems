class Graph {
public:
    map<int,vector<pair<int,int>>> adj;
    int V;

    Graph(int n, vector<vector<int>>& edges) {
        V=n;
      for(auto i:edges){
          adj[i[0]].push_back({i[1],i[2]});
      }  
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>dis(V,1e8);

        pq.push({0,node1});
        dis[node1]=0;

        while(!pq.empty()){
            auto u=pq.top();
            pq.pop();

            for(auto i:adj[u.second]){
                int d=i.second;
                int v=i.first;

                if((dis[u.second]+d) < dis[v]){
                    dis[v]=dis[u.second]+d;
                    pq.push({dis[v],v});
                }
            }
        }

        return dis[node2]==1e8 ? -1 : dis[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */