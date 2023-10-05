class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int e1=INT_MIN,e2=INT_MIN,c1=0,c2=0;

        for(auto i:nums){
            if(  e2!=i && (c1==0)){
                e1=i;
                c1++;
            }
            else if(e1!=i && ( c2==0 )){
                e2=i;
                c2++;
            }
            else if(e1!=i && e2==i) c2++;
            else if(e2!=i && e1==i) c1++;
            else{
                c2--;
                c1--;
            }
        }

        c1=0;c2=0;
        for(auto i:nums){
            if(i==e1) c1++;
            else if(i==e2) c2++;
        }

        vector<int>ans;
        if(c1>(nums.size()/3)) ans.push_back(e1);
        if(c2>(nums.size()/3)) ans.push_back(e2);
        return ans;
    }
};