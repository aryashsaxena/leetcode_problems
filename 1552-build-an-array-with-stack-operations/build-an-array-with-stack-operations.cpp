class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int j=1;
        for(auto i:target){
            if(j==i){
                ans.push_back("Push");
                j++;
            }
            else{
                while(j!=i){
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    j++;
                }
                ans.push_back("Push");
                j++;
            }
                    // cout<<j;
        }

        return ans;
    }
};