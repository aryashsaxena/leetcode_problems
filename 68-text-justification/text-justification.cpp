class Solution {
public:
    string f(int i,int j,int each,int ex,int mx,vector<string>&word){
        string t="";
        string tmp="";
        for(int k=1;k<=each;k++) tmp+=" ";

        for(int k=i;k<j;k++){
            if(k==(j-1)){
                t+=word[k];
                continue;
            }
            t+=word[k]+tmp;

            if(ex>0){
                t+=" ";
                ex--;
            }
        }
        
        while(t.size()<mx) t+=" ";

        return t;
    }

    vector<string> fullJustify(vector<string>& word, int mxw) {
        vector<string> ans;

        int i=0;
        while(i<word.size()){
            int sz=word[i].size();
            int j=i+1;
            int gp=0;

            while(j<word.size() && (sz+1+word[j].size()+gp)<=(mxw)){
                sz+=word[j].size();
                j++;
                gp++;
            }

            int rem=(mxw-sz);
            int each= gp==0 ? 0: (rem/gp);
            int ex= gp==0 ? 0: (rem%gp);

            if(j==word.size()){
                each=1;
                ex=0;
            }

            ans.push_back(f(i,j,each,ex,mxw,word));

            i=j;
        }

        return ans;
    }
};