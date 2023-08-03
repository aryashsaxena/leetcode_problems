//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        unordered_map<int,vector<pair<int,int>>> adj;
        
        for(auto v:edges){
            adj[v[0]].push_back({v[1],v[2]});
        }
        
        vector<int> dist(N,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,0});
        dist[0]=0;
        
        while(!q.empty()){
            auto i=q.top();
            q.pop();
            
            int u=i.second;
            for(auto j:adj[u]){
                int d=j.second+i.first;
                
                if(d<dist[j.first]){
                    dist[j.first]=d;
                    q.push({d,j.first});
                }
            }
        }
        
        vector<int> ans;
        for(auto i:dist){
            if(i==INT_MAX) ans.push_back(-1);
            else ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends