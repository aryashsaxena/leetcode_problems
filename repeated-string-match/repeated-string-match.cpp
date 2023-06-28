class Solution {
public:
    bool check(string &a,string &b){
        
        if(a=="" || b=="") return false;

        for(int i=0;i<=a.size()-b.size();i++){
            if(a.substr(i,b.size())==b) return true;
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string temp="";
        int count=0;

        while(temp.size()<b.size()){
            temp+=a;
            count++;
        }

        if(temp==b) return count;
        if(check(temp,b)) return count;

        temp+=a;
        if(check(temp,b)) return count+1;
        return -1;
    }
};