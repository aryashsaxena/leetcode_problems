class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        for(auto i:s) mp[i]++;

        priority_queue<pair<int,char>> pq;
        for(auto i:mp) pq.push({i.second,i.first});

        string t=s;
        int j=0;
        vector<int> vis(s.size(),0);

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int k=j;
            int c=it.first;
            while(c--){
                while(vis[j]) j=(j+1)%s.size();
                
                t[j]=it.second;
                vis[j]=1;
                j=(j+2)%s.size();
            }

            if(j==s.size()-1 || j==0){
                j=k+1;
            }
        }

        cout<<t<<endl;
        for(int i=1;i<s.size();i++){
            if(t[i]==t[i-1]) return "";
        }
        return t;
    }
};