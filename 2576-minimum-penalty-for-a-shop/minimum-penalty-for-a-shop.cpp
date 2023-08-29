class Solution {
public:
    int bestClosingTime(string s) {
       int y=0,n=0;
       for(auto i:s){
           if(i=='Y') y++;
           else n++;
       }
       int mn=0,mnc=y,count=y;

       int i=0,N=0;
       while(i<s.size()){
           if(s[i]=='Y') y--;
           else N++;

           count=y+N;
            // cout<<count<<" ";
           if(count<mnc){
               mnc=count;
               mn=i+1;
           }
            i++;
       }
       return mn;
    }
};