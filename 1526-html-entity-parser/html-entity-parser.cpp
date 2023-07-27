class Solution {
public:
    string entityParser(string text) {
        unordered_map<string,string>m;

        m.insert({"&quot;","\""});
        m.insert({"&apos;","\'"});
        m.insert({"&amp;","&"});
        m.insert({"&gt;",">"});
        m.insert({"&lt;","<"});
        m.insert({"&frasl;","/"});

        string ans="",s="";
        int i=0;

        while(i<text.size()){
            if(text[i]==' '){
                ans+=s+" ";
                s="";
                i++;
            }
            if(i<text.size()){
                if(text[i]=='&'){
                    ans+=s;
                    s="";
                }
                 s+=text[i];
                 if(m.count(s)){
                     ans+=m[s];
                     s="";
                 }
            }
            i++;
        }
         if(m.count(s)){
                 ans+=m[s];
                 s="";
        }
        else ans+=s;
        
        return ans;
    }
};