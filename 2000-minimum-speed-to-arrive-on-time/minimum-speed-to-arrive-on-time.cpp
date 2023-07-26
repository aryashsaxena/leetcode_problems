class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // sort(dist.begin(),dist.end());

        int l=1,h=1e7;

        int ans=-1;
        while(l<=h){
            int mid=(l+h)>>1;

            double sum=0.0;
            for(int i=0;i<dist.size()-1;i++){
                sum+=ceil(((double)dist[i]/(double)mid));
            }
            sum+=((double)dist[dist.size()-1]/(double)mid);

            if(sum>hour) l=mid+1;
            else{
                ans=mid; 
                h=mid-1;}
        }
        return ans ;
    }
};