class Solution {
public:
    bool check(vector<int>&a,vector<int>&b){
        if(a[1]<b[0]) return false;
        if(b[1]<a[0]) return false;
        return true;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });

        vector<int> v={pairs[0][0],pairs[0][1]};
        int count=1,mx=1;
        for(int i=1;i<pairs.size();i++){
            if(!check(v,pairs[i])){
                count++;
                v=pairs[i];
            }
            mx=max(mx,count);
        }
        return mx;
    }
};