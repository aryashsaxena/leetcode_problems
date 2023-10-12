/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int l=0,h=arr.length()-1;

        int ans=-1;
        while(l<=h){
            int mid=(l+h)>>1;
            int x=arr.get(mid);
            
            if(x ==target){
                ans=mid;
                h=mid-1;
            }
            else{
               if( mid-1>=0 && mid+1<arr.length() &&  x <arr.get(mid+1) && x >arr.get(mid-1)){
                   if(x >target) h=mid-1;
                   else if(x <target) l=mid+1;
               }
               else if(mid-1 >=0 && x >arr.get(mid-1)){
                   if(x >target) h=mid-1;
                   else l=mid+1;
               }
               else if(mid+1<arr.length() && x <arr.get(mid+1)){
                   if(x >target) h=mid-1;
                   else l=mid+1;
               }
               else
                h=mid-1;
            }
        }

        if(ans!=-1) return ans;

        l=0,h=arr.length()-1;
        while(l<=h){
            int mid=(l+h)>>1;
            int x=arr.get(mid);
            
            if(x ==target){
                ans=mid;
                h=mid-1;
            }
            else{
               if( mid-1>=0 && mid+1<arr.length() &&  x >arr.get(mid+1) && x <arr.get(mid-1)){
                   if(x >target) l=mid+1;
                   else if(x <target) h=mid-1;
               }
               else if(mid-1 >=0 && x <arr.get(mid-1)){
                   if(x <target) h=mid-1;
                   else l=mid+1;
               }
               else if(mid+1<arr.length() && x >arr.get(mid+1)){
                   if(x<target) h=mid-1;
                   else l=mid+1;
               }
               else
                l=mid+1;
            }
        }
        return ans;
    }
};