class Solution {
public:
    unordered_map<char,string> m;
    vector<string> ans;

    void  f(int i,string &s,string dgt){
        if(i>=dgt.size()){
            ans.push_back(s);
            return;
        }

        string t=m[dgt[i]];
        for(int j=0;j<t.size();j++){
            s.push_back(t[j]);
            f(i+1,s,dgt);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return ans;

        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        
        string s="";
        f(0,s,digits);

        return ans;
    }
};