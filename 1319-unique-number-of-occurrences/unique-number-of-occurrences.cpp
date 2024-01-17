class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        set<int> st;
        sort(arr.begin(),arr.end());

        if(arr.size()==2)
        {
           if(arr[0]==arr[1])
           return true;
           return false;
        }
            
        int count=1;
        
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]!=arr[i-1])
            {
                if(st.count(count))
                 return false;
                 st.insert(count);
                 count=1;

            }
            else
            count++;
        }
        int n=arr.size();

        if(arr[n-1]!=arr[n-2] && st.count(1)) return false;
        
        return true;
    }
};