class Node{
    public:
    int key;
    int val;
    Node *prev,*next;
    Node(int _key,int _val){
        key=_key;
        val=_val;

    }
};
class LRUCache {
    int cap=0;
    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);
    unordered_map<int,Node*>mpp;


public:
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(Node*newnode){
        Node* temp=head->next;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
        head->next=newnode;
    }
    void deletenode(Node*newnode){
        Node*delprev=newnode->prev;
        Node*delnext=newnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;

    }
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* temp=mpp[key];
            int res=temp->val;
            mpp.erase(key);
            deletenode(temp);
            addnode(temp);
            mpp[key]=head->next;
            return res;

        }
        return -1;

    }

    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node*temp=mpp[key];
            mpp.erase(key);
            deletenode(temp);
        }
        if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);

        }
        addnode(new Node(key,value));
        mpp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */