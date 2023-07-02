class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
    
        long long ans=0;
        map<long,long> m;

        int i=0,j=0;
        while(j<nums.size()){
            m[nums[j]]++;

            while(m.size()>0 && (m.rbegin()->first-m.begin()->first)>2){
                m[nums[i]]--;
                if(m[nums[i]]==0)
                m.erase(nums[i]);

                i++;
            }

            ans+=j-i+1;

            j++;
        }

        return ans;
       
    }
};