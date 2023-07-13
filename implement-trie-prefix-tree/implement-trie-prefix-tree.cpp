class Trie {
    class Node{
        public:

        Node *link[26];
        bool flg;

    };

public:
    Node *root;

    Trie() {
        root=new Node();
    }
    
    void insert(string s) {
        Node* node=root;

        for(int i=0;i<s.size();i++){
            if(node->link[s[i]-'a']==NULL){
                node->link[s[i]-'a']=new Node();
            }

            node=node->link[s[i]-'a'];
        }
        node->flg=true;
    }
    
    bool search(string s) {
        Node* node=root;

        for(int i=0;i<s.size();i++){
            if(node->link[s[i]-'a']==NULL) return false;

            node=node->link[s[i]-'a'];
        }
        return node->flg;
    }
    
    bool startsWith(string s) {
        Node* node=root;

        for(int i=0;i<s.size();i++){
            if(node->link[s[i]-'a']==NULL) return false;

            node=node->link[s[i]-'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */