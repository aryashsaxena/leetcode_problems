class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        unordered_map<int,int> m;

        int mx=arr[0];
        for(int i=1;i<arr.size();i++){
            mx=max(mx,arr[i]);

            if(arr[i-1]>arr[i]){
                arr[i]=arr[i-1];
                m[arr[i-1]]++;
            }
            else m[arr[i]]++;

            if(m[arr[i-1]]==k) return arr[i-1];
            else if(m[arr[i]]==k) return arr[i];
        }

        return mx;
    }
};