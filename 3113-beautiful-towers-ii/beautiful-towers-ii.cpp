class Solution {
public:
    long long maximumSumOfHeights(vector<int>& mh) {
        int n=mh.size();
        vector<int>left(n,-1),right(n,n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && mh[st.top()]>=mh[i]) st.pop();

            if(!st.empty()) left[i]=st.top();
            st.push(i);
        }

        st=stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && mh[st.top()]>=mh[i]) st.pop();

            if(!st.empty()) right[i]=st.top();
            st.push(i);
        }

        vector<long long> lsum(n,0),rsum(n,0);
        lsum[0]=mh[0];

        for(int i=1;i<n;i++){
            int c=i-left[i];
            lsum[i]+=1LL*c*mh[i];

            if(left[i]!=-1) lsum[i]+=lsum[left[i]];
        }

        rsum[n-1]=mh[n-1];
        for(int i=n-2;i>=0;i--){
            int c=right[i]-i;
            
            rsum[i]+=1LL*c*mh[i];
            if(right[i]!=n){
                rsum[i]+=rsum[right[i]];
            }
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,lsum[i]+rsum[i]-mh[i]);
        }

        return ans;
    }
};