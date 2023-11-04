class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l=0;
        for(auto i:left) l=max(l,i);
        
        for(auto i:right){
            l=max(l,n-i);
        }
        return l;
    }
};