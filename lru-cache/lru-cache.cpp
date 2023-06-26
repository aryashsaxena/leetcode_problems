class LRUCache {
public:
    class Node{
        public:

        int k,val;
        Node* prev, *next;

        Node(int key,int value){
            k=key;
            val=value;
        }
    };

    Node* head,*last;
    int sz;
    unordered_map<int,Node*> m;

    LRUCache(int capacity) {
        sz=capacity;
        head=new Node(-1,-1);
        last= new Node(-1,-1);

        head->next=last;
        last->prev=head;
    }
    
    void add(Node* node){
        Node* temp=head->next;
        head->next=node;
        node->prev=head;
        node->next=temp;
        temp->prev=node;
    }

    void del(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    int get(int key) {
        if(!m.count(key)) return -1;

        int x=m[key]->val;
        del(m[key]);
        add(m[key]);

        return x;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            Node* temp=m[key];
            m.erase(key);
            del(temp);
        }
        if(m.size()==sz){
            m.erase(last->prev->k);
            del(last->prev);
        }
        Node* node=new Node(key,value);
        add(node);
        m[key]=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */