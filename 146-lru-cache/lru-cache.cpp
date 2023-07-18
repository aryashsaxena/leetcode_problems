class LRUCache {
    private:
    class Node{
        public:
        int k;
        int val;
        Node* prev,*next;

        Node(int key,int value){
            k=key;
            val=value;
        }
    };
    
public:
    Node* head,*tail;
    int size;
    map<int,Node *> m;

    LRUCache(int capacity) {
        size=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(Node* node){
        Node* temp=head->next;
        head->next=node;
        node->next=temp;
        temp->prev=node;
        node->prev=head;
    }

    void deletenode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    int get(int key) {
        if(!m.count(key)) return -1;
        Node* node=m[key];
        deletenode(node);
        addnode(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            deletenode(m[key]);
            m.erase(key);
        }

        else if(m.size()==size){
            m.erase(tail->prev->k);
            deletenode(tail->prev);
        }

        Node* node=new Node(key,value);
        addnode(node);
        m[key]=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */