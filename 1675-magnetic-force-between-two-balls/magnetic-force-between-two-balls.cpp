class Solution {
public:
    int get(vector<int> &nums,int mid){
        int count=1;
        int pre=nums[0];


        for(int i=1;i<nums.size();i++){
           if(nums[i]-pre>=mid){
               count++;
               pre=nums[i];
           }
        }    
        return count;
    }

    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());

        int l=1;
        int h=pos[pos.size()-1]-pos[0];
        int ans=-1;

        while(l<=h){
            int mid=(l+h)>>1;

            int x=get(pos,mid);

            if(x<m) h=mid-1;
            else{
                ans=mid;
                l=mid+1;
            }
        }
        return ans;
    }
};