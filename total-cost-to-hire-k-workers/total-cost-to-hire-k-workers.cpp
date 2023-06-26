class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candi) {
        long long ans=0;

        priority_queue<int,vector<int>,greater<int>> left,right;
        int i=0,j=costs.size()-1;

        while(k--){
            while(left.size()<candi && i<=j){
                left.push(costs[i++]);
            }
            while(right.size()<candi && j>=i){
                right.push(costs[j--]);
            }

            int c1=0,c2=0;

            c1=left.size()>0 ? left.top() : INT_MAX;
            c2=right.size()>0 ? right.top() : INT_MAX;
            
            if(c1<=c2){
                ans+=left.top();
                left.pop();

            }
            else{
                ans+=right.top();
                right.pop();

            }
        }


        return ans;
    }
};