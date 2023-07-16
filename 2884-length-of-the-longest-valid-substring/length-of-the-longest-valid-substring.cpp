class Solution {
    private:
    class Node{
        public:
            Node* links[27];
            bool flag;

            Node(){
                flag=false;
                for(int i=0;i<27;i++){
                    links[i]=NULL;
                }
            }
    };

    public:
        Node* root=new Node();

        void insert(string &s){
            Node* node=root;
            
            for(int i=0;i<s.size();i++){
                if(!node->links[s[i]-'a']){
                    node->links[s[i]-'a']=new Node();
                }
                node=node->links[s[i]-'a'];
            }

            node->flag=true;
        }

        bool search(string &s,int i,int j){
            Node* node=root;

            for(;i<=j;i++){
                if(!node->links[s[i]-'a']) return false;
                node=node->links[s[i]-'a'];

                if(node->flag==true) return true;
            }
            return node->flag;
        }

        int longestValidSubstring(string s, vector<string>& forbidden) {
            
            for(auto t:forbidden){
                insert(t);
            }

            int j=s.size()-1,ans=0;
            for(int i=s.size()-1;i>=0;i--){

                while(i<=j && search(s,i,j)) j--;

                ans=max(ans,j-i+1);
            }
            return ans;
        }
};