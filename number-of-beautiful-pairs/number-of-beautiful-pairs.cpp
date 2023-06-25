class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int count=0;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int n=nums[i];
                int a=0;
                while(n){
                    a=n%10;
                    n/=10;
                }

                int b=nums[j]%10;
                if(__gcd(a,b)==1) count++;
            }
        }
        return count;
    }
};