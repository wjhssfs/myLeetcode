// 432. All O`one Data Structure
// Implement a data structure supporting the following operations:

// Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
// Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
// GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
// GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
// Challenge: Perform all these in O(1) time complexity.

class AllOne {
public:
	/** Initialize your data structure here. */
	AllOne() {
	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		if (!dataMap.count(key)) {
			if (orderList.size() && orderList.back().first == 1) {
				orderList.back().second.insert(key);
				dataMap[key] = prev(orderList.end());
			}
			else {
				orderList.push_back(make_pair(1, unordered_set<string>({ key })));
				dataMap[key] = prev(orderList.end());
			}
		}
		else {
			auto it = dataMap[key];
			if (it != orderList.begin() && prev(it)->first == it->first + 1) {
				prev(it)->second.insert(key);
				dataMap[key] = prev(it);
			}
			else {
				orderList.insert(it, make_pair(it->first + 1, unordered_set<string>({ key })));
				dataMap[key] = prev(it);
			}
			it->second.erase(key);
			if (it->second.empty()) {
				orderList.erase(it);
			}
		}
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		if (!dataMap.count(key)) return;
		auto it = dataMap[key];
		if (it->first == 1) {
			it->second.erase(key);
			if (it->second.empty()) {
				orderList.erase(it);
			}
			dataMap.erase(key);
		}
		else {
			if (next(it) != orderList.end() && next(it)->first == it->first - 1) {
				next(it)->second.insert(key);
				dataMap[key] = next(it);
			}
			else {
				orderList.insert(next(it), make_pair(it->first - 1, unordered_set<string>({ key })));
				dataMap[key] = next(it);
			}

			it->second.erase(key);
			if (it->second.empty()) {
				orderList.erase(it);
			}
		}
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (orderList.empty()) return "";
		return *orderList.front().second.begin();
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (orderList.empty()) return "";
		return *orderList.back().second.begin();
	}

private:
	unordered_map<string, list<pair<int, unordered_set<string>>>::iterator> dataMap;
	list<pair<int, unordered_set<string>>> orderList;
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