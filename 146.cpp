// https://leetcode.com/problems/lru-cache/

struct Node {
    int key, value;
    Node *next, *prev;
};

class LRUCache {
    int capacity, size;
    Node *head, *tail;
    unordered_map<int, Node*> cache;
    
    void remove(Node* node) {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
    
    void addTail(Node* node) {
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
        size++;
    }
    
    void evictFromCache() {
        Node* node = head->next;
        remove(node);
        cache.erase(node->key);
        delete node;
    }
    
public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        remove(cache[key]);
        addTail(cache[key]);
        return cache[key]->value;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            cache[key]->value = value;
        } else {
            Node* node = new Node();
            node->key = key;
            node->value = value;
            node->prev = node->next = NULL;
            if (size == capacity) {
                evictFromCache();
            }
            addTail(node);
            cache[key] = node;
        }   
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

