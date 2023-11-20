class Solution {
public:
    int garbageCollection(vector<string>& gar, vector<int>& tl) {
        int tg=0,tp=0,tm=0;
        int g=0,p=0,m=0;

        for(auto i:gar[0]){
            if(i=='G') g++;
            else if(i=='P') p++;
            else if(i=='M') m++;
        }

        for(int i=1;i<gar.size();i++){
            tg+=tl[i-1];
            tp+=tl[i-1];
            tm+=tl[i-1];

            int c1=0,c2=0,c3=0;
            for(auto ch:gar[i]){
                if(ch=='G') c1++;
                else if(ch=='P') c2++;
                else if(ch=='M') c3++;
            }
            if(c1){
                g+=tg+c1;
                tg=0;
            }
            if(c2){
                p+=tp+c2;
                tp=0;
            } 
            if(c3){
                m+=tm+c3;
                tm=0;
            }
        }
        return g+p+m;
    }
};