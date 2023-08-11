class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
       for(int i=0;i<cardPoints.size();i++)
       {
           sum=sum+cardPoints[i];
       }
       int n=cardPoints.size();
       int wind=0;
       int j=0;
       while(j<(n-k)){
           wind=wind+cardPoints[j];
           j++;
       }

       int ans=sum-wind;
       int i=0;
       while(j<n)
       {
        //    cout<<wind<<" ";
          
           wind=wind-cardPoints[i];
           wind=wind+cardPoints[j];

            ans=max(ans,sum-wind);
           i++;
           j++;
       }
    //    cout<<"% "<<sum<<" ";
    return ans;
    }
};