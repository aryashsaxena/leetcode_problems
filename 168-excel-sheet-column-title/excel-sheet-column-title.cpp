class Solution {
public:
    string convertToTitle(int x) {
        string t="";
        int f=0;

        while(x){
            int i;
            if(x%26!=0)
            i=(x%26);
            else if(x<=26) i=x;
            else{
                i=26;
                x=x/26;
                x--;
                f=1;
            }
            t=char(i-1+'A')+t;

            if(x==26 && f==0) break;
            if(f==0)
            x/=26;

            f=0;
          
            cout<<i<<" -? "<<x<<" ";
        }
        return t;
    }
};