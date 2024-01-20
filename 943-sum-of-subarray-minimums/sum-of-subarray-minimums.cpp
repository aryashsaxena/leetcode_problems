class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        const int mod=1e9+7;
        vector<int> l(n),r(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();

            if(st.empty()) l[i]=i+1;
            else l[i]=i-st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        st.push(n-1);
        r[n-1]=1;

        for(int i=n-2;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();

            if(st.empty()) r[i]=n-i;
            else r[i]=st.top()-i;

            st.push(i);
        }

        long long count=0;
        for(int i=0;i<n;i++){
            long long pro=(l[i]*r[i])%mod;
            count+=(pro*arr[i])%mod; 
        }

        return count%mod;
    }
};