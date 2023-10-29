class Solution {
public:
    int poorPigs(int n, int md, int mt) {
        int x=0;

        while(pow((mt/md + 1),x)<n){
            x++;
        }
        return x;
    }
};