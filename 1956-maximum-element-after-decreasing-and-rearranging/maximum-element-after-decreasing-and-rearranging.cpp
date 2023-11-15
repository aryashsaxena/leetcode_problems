class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        int x=1;
        arr[0]=1;
        for(int i=1;i<arr.size();i++){
           if(abs(arr[i]-arr[i-1])>1){
               arr[i]=arr[i-1]+1;
           }
        }

        return arr.back();

    }
};