class Solution {
public:
    vector<string> ans;
    unordered_map<char,string> m;


    void f(int i,string &s,string &str){
        if(i==str.size()){
            ans.push_back(s);
            return;
        }

        string t=m[str[i]];
        for(int j=0;j<t.size();j++){
            s.push_back(t[j]);
            f(i+1,s,str);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return ans;
    
        m.insert({'2',"abc"});
        m.insert({'3',"def"});
         m.insert({'4',"ghi"});
         m.insert({'5',"jkl"});
         m.insert({'6',"mno"});
         m.insert({'7',"pqrs"});
         m.insert({'8',"tuv"});
         m.insert({'9',"wxyz"});   

         string s="";
         f(0,s,digits);
         return ans;
    }
};