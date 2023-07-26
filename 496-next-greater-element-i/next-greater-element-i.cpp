class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n=nums2.size();
        for(int i=0;i<n;i++){
            mp[nums2[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
             int ch=0;
            if(mp.find(nums1[i])!=mp.end()){
            int j=mp[nums1[i]]+1;
           
            while(j<n){
                if(nums2[j]>nums1[i]) {
                    ans.push_back(nums2[j]);
                    ch=1;
                    break;
                    }
                    j++;
                }
            }
            if(ch==0)
        ans.push_back(-1);
        }
       return ans; 
    }
};