// 706. Design HashMap

// Design a HashMap without using any built-in hash table libraries.

// To be specific, your design should include these functions:

// put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
// get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
// remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.

// Example:

// MyHashMap hashMap = new MyHashMap();
// hashMap.put(1, 1);          
// hashMap.put(2, 2);         
// hashMap.get(1);            // returns 1
// hashMap.get(3);            // returns -1 (not found)
// hashMap.put(2, 1);          // update the existing value
// hashMap.get(2);            // returns 1 
// hashMap.remove(2);          // remove the mapping for 2
// hashMap.get(2);            // returns -1 (not found) 

// Note:

// All keys and values will be in the range of [0, 1000000].
// The number of operations will be in the range of [1, 10000].
// Please do not use the built-in HashMap library.

class MyHashMap {
    struct Node {
        Node* next;
        int v;
        int k;
        Node(int _k, int _v) : k(_k), v(_v), next(nullptr){}
    };
    
    vector<Node> buckets;
    Node* find(int key) {
        size_t i = key % buckets.size();
        Node* p = &buckets[i];
        while (p->next && p->next->k != key) p = p->next;
        return p;
    }
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        buckets = vector<Node>(10000, Node(-1, -1));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto p = find(key);
        if (p->next == nullptr) {
            p->next = new Node(key, value);
        } else {
            p->next->v = value;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto p = find(key);
        return p->next ? p->next->v : -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto p = find(key);
        if (p->next) p->next = p->next->next;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */