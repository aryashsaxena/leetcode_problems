class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int l=0,h=matrix.size()*matrix[0].size();
        h--;
        while(l<=h){
            int mid=(l+h)/2;

            int x=matrix[mid/m][mid%m];
            if(x==target) return true;
            if(x<target) l=mid+1;
            else h=mid-1;
        }
        return false;
    }
};