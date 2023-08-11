class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,count=0;
        int mx=0;
        while(j<nums.size()){
            if(nums[j]==0) count++;

            while(count>k){
                if(nums[i]==0) count--;
                i++;
            }
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;

        // int i=0;
        // int count=0,mx=0;
        // while(i<nums.size()){
        //     if(nums[i]==1) count++;
        //     else{
        //         int j=i;
        //         int z=-1;
        //         int c=0,temp=0;
        //         while(j<nums.size()){
        //             if(nums[j]==0){
        //                 if(c<k)
        //                 c++;
        //                 else break;
        //             }
        //             if(nums[j]==1 && z==-1) z=j;
        //             temp++;
        //             j++;
        //         }
        //         mx=max(mx,count+temp);
        //         count=0;
        //         i=j;
        //         continue;
        //     }
        //     i++;
        // }
        // mx=max(mx,count);

        // return mx;
    }
};