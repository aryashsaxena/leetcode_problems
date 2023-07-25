class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0;
        int h=arr.size()-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(mid+1<arr.size() && arr[mid]<arr[mid+1])
                l=mid+1;
            
            else if(mid-1>=0 && arr[mid]<arr[mid-1])
                h=mid-1;
            
            else 
                return mid;
        }
        return l;
    }
};