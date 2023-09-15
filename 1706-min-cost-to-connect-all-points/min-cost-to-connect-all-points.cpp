class Solution {
public:
    int n;
    vector<int> p;
    vector<int> rank;

    int find(int i){
        if(i==p[i]) return i;

        return p[i]=find(p[i]);
    }

    void uniion(int x,int y){
        int i=find(x);
        int j=find(y);

        if(i==j) return;

        if(rank[i]<rank[j]){
            p[i]=j;
        }
        else if(rank[i]>rank[j]){
            p[j]=i;
        }
        else{
            p[j]=i;
            rank[i]++;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& pt) {
        n=pt.size();
        p.resize(n,0);
        rank.resize(n,0);

        for(int i=0;i<n;i++) p[i]=i;

        // unordered_map<int,vector<pair<int,int>>> adj;
        vector<vector<int>> nums;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d=abs(pt[i][0]-pt[j][0])+abs(pt[i][1]-pt[j][1]);

                nums.push_back({d,i,j});

                // adj[i].push_back({j,d});
                // adj[j].push_back({i,d});
            }
        }

        sort(nums.begin(),nums.end());

        int count=0;
       for(auto i:nums){
           if(find(i[1])==find(i[2])) continue;

           count+=i[0];
           uniion(i[1],i[2]);
       }

        return count;

        // int count=0;
        // priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        // pq.push({0,0});

        // vector<int> vis(n+1,0);

        // while(!pq.empty()){
        //     auto i=pq.top();
        //     pq.pop();

        //     if(vis[i[1]]) continue;

        //     count+=i[0];
        //     vis[i[1]]=1;

        //     for(auto j:adj[i[1]]){
        //         if(vis[j.first]) continue;

        //         pq.push({j.second,j.first});
        //     }
        // }
        // return count;
    }
};