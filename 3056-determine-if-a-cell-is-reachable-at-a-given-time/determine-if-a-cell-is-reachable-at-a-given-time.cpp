class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy) return t!=1;

        int x1=abs(sx-fx),y1=abs(sy-fy);
        int d=min(x1,y1);
        x1-=d;
        y1-=d;

        int count=x1+y1+d;
        return count<=t;
    }
};