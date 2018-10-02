// 705. Design HashSet

// Design a HashSet without using any built-in hash table libraries.

// To be specific, your design should include these functions:

// add(value): Insert a value into the HashSet. 
// contains(value) : Return whether the value exists in the HashSet or not.
// remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

// Example:

// MyHashSet hashSet = new MyHashSet();
// hashSet.add(1);         
// hashSet.add(2);         
// hashSet.contains(1);    // returns true
// hashSet.contains(3);    // returns false (not found)
// hashSet.add(2);          
// hashSet.contains(2);    // returns true
// hashSet.remove(2);          
// hashSet.contains(2);    // returns false (already removed)

// Note:

// All values will be in the range of [0, 1000000].
// The number of operations will be in the range of [1, 10000].
// Please do not use the built-in HashSet library.

class MyHashSet {
    struct Node {
        int k;
        Node* next;
        Node(int _k) : k(_k), next(nullptr) {}
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
    MyHashSet() {
        buckets = vector<Node>(10000, Node(-1));
    }
    
    void add(int key) {
         auto p = find(key);
        if (p->next == nullptr) p->next = new Node(key);
    }
    
    void remove(int key) {
        auto p = find(key);
        if (p->next) p->next = p->next->next;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto p = find(key);
        return p->next;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */

   vector<bool> hashSet;
    MyHashSet() {
        for(int i=0;i<=1000000;i++) hashSet.push_back(false);
    }
    
    void add(int key) {
        hashSet[key]=true;
    }
    
    void remove(int key) {
        hashSet[key]=false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hashSet[key];
    }