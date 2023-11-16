class Solution {
public:
    vector<string> ans;
    
    void f(string &s,int n)
    {
        if(s.size()==n)
        {
            ans.push_back(s);
            return ;
        }
        
        s.push_back('1');
        f(s,n);
        s.pop_back();
        s.push_back('0');
        f(s,n);
        s.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string s="";
        int n=nums.size();
        f(s,n);
        
       
        map<string,int> st;
        for(auto it:nums)
            st[it];
        
        for(auto i:ans)
        {
            if(!st.count(i))
                return i;
        }
        return "";
    }
};