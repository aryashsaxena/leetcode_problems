//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    stack<int> st;
    
    void f(int i,vector<int> adj[],unordered_set<int> &vis){
        vis.insert(i);
        
        for(auto j:adj[i]){
            if(vis.count(j)) continue;
            
            f(j,adj,vis);
        }
        st.push(i);
    }
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    unordered_set<int> vis;
	    for(int i=0;i<V;i++){
	        if(vis.count(i)){
	            continue;
	        }
	        
	        f(i,adj,vis);
	    }
	    
	    vis.clear();
	    int ans=st.top();
	    f(ans,adj,vis);
	    
	    if(vis.size()!=V) return -1;
	    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends