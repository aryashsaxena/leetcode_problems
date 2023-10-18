//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
        
        unordered_map<int,vector<int>> m;
        vector<int> ind(v,0);
        
        for(int i=0;i<v;i++){
            for(auto j:adj[i]){
                m[j].push_back(i);
                ind[i]++;
            }
        }
        
        queue<int>q;
        vector<int> ans;
        
        for(int i=0;i<v;i++){
            if(ind[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int i=q.front();
            q.pop();
            
            ans.push_back(i);
            
            for(auto j:m[i]){
                ind[j]--;
                
                if(ind[j]==0) q.push(j);
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends