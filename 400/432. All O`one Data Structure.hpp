// 432. All O`one Data Structure
// Implement a data structure supporting the following operations:

// Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
// Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
// GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
// GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
// Challenge: Perform all these in O(1) time complexity.
class AllOne {
	list<pair<int, unordered_set<string>>> orderedCount;
	unordered_map<string, list<pair<int, unordered_set<string>>>::iterator> keyToSet;
public:
	/** Initialize your data structure here. */
	AllOne() {}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		if (keyToSet.count(key) == 0) {
			if (orderedCount.empty() || orderedCount.front().first > 1) {
				keyToSet[key] = orderedCount.insert(orderedCount.begin(), { 1,{key}});
			}
			else {
				keyToSet[key] = orderedCount.begin();
				orderedCount.front().second.insert(key);
			}
		}
		else {
			auto it = keyToSet[key];
			auto itN = next(it);
			if (itN == orderedCount.end() || itN->first > it->first + 1) {
				keyToSet[key] = orderedCount.insert(itN, {it->first + 1, {key}});
			}
			else {
				keyToSet[key] = itN;
				itN->second.insert(key);
			}
			it->second.erase(key);
			if (it->second.empty()) orderedCount.erase(it);
		}
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		if (keyToSet.count(key) == 0) return;
		auto it = keyToSet[key];
		it->second.erase(key);
		if (it->first != 1) {
			auto itP = prev(it);
			if (itP == orderedCount.end() || itP->first < it->first - 1) {
				keyToSet[key] = orderedCount.insert(it, {it->first - 1, {key}});
			}
			else {
				itP->second.insert(key);
				keyToSet[key] = itP;
			}
		}
		if (it->second.empty()) {
			if (it->first == 1) keyToSet.erase(key);
			orderedCount.erase(it);
		}
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (orderedCount.empty()) return "";
		return *orderedCount.back().second.begin();
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (orderedCount.empty()) return "";
		return *orderedCount.front().second.begin();
	}
};
/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */

class AllOne {
public:

    void inc(string key) {
        
        // If the key doesn't exist, insert it with value 0.
        if (!bucketOfKey.count(key))
            bucketOfKey[key] = buckets.insert(buckets.begin(), {0, {key}});
            
        // Insert the key in next bucket and update the lookup.
        auto next = bucketOfKey[key], bucket = next++;
        if (next == buckets.end() || next->value > bucket->value + 1)
            next = buckets.insert(next, {bucket->value + 1, {}});
        next->keys.insert(key);
        bucketOfKey[key] = next;
        
        // Remove the key from its old bucket.
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }

    void dec(string key) {

        // If the key doesn't exist, just leave.
        if (!bucketOfKey.count(key))
            return;

        // Maybe insert the key in previous bucket and update the lookup.
        auto prev = bucketOfKey[key], bucket = prev--;
        bucketOfKey.erase(key);
        if (bucket->value > 1) {
            if (bucket == buckets.begin() || prev->value < bucket->value - 1)
                prev = buckets.insert(bucket, {bucket->value - 1, {}});
            prev->keys.insert(key);
            bucketOfKey[key] = prev;
        }
        
        // Remove the key from its old bucket.
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }

    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }
    
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }

private:
    struct Bucket { int value; unordered_set<string> keys; };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> bucketOfKey;
};