class Solution {
public:
    void mindist(unordered_map<int,vector<int>>&adj,vector<int>&dist,int u){
        queue<int> q;
        q.push(u);
        dist[u]=0;

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto v:adj[u]){
                if(dist[v]==-1){
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
        }
    }

    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& pat) {
        unordered_map<int,vector<int>> adj;
        int n=pat.size();
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> dist(n,-1);
        mindist(adj,dist,0);

        int ans=0;
        for(int i=1;i<n;i++){
            int firstmsgrec=2*dist[i];
            int extra=(firstmsgrec-1)/pat[i];
            int lastmsgsent=extra*pat[i];
            int lastmsgrec=lastmsgsent+firstmsgrec;

            ans=max(ans,lastmsgrec);
        }
        return ans+1;
    }
};