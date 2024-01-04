class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        
        for(auto i:nums) m[i]++;
        
        int count=0;
        for(auto i:m){
            int x=i.second;
            
            if(x==1) return -1;
            
            while(x>2){
                x-=3;
                count++;
            }
            if(x!=0) count++;
        }
        return count;
    }
};