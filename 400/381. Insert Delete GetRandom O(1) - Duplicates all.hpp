// 381. Insert Delete GetRandom O(1) - Duplicates allowed

// Design a data structure that supports all following operations in average O(1) time.

// Note: Duplicate elements are allowed.
// insert(val): Inserts an item val to the collection.
// remove(val): Removes an item val from the collection if present.
// getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
// Example:

// // Init an empty collection.
// RandomizedCollection collection = new RandomizedCollection();

// // Inserts 1 to the collection. Returns true as the collection did not contain 1.
// collection.insert(1);

// // Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
// collection.insert(1);

// // Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
// collection.insert(2);

// // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
// collection.getRandom();

// // Removes 1 from the collection, returns true. Collection now contains [1,2].
// collection.remove(1);

// // getRandom should return 1 and 2 both equally likely.
// collection.getRandom();

class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {
		srand(time(0));
	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		bool didNotContain = s[val].empty();
		s[val].insert(v.size());
		v.push_back(val);
		return didNotContain;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		if (s[val].empty()) return false;
		int lastV = v.back(), lastP = v.size() - 1;
		if (lastV != val) {
			int vPos = *(s[val].begin());
			s[lastV].erase(lastP);
			s[lastV].insert(vPos);
			s[val].erase(vPos);
			v[vPos] = lastV;
		}
		else {
			s[val].erase(lastP);
		}
		v.pop_back();
		return true;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		return v[rand() % v.size()];
	}
	unordered_map<int, unordered_set<int>> s;
	vector<int> v;
};

// https://discuss.leetcode.com/topic/54381/c-128m-solution-real-o-1-solution
// There are two data member in the solution

// a vector nums
// an unordered_map m
// The key of m is the val, the value of m is a vector contains indices where the val appears in nums.
// Each element of nums is a pair, the first element of the pair is val itself, the second element of the pair is an index into m[val].
// There is a relationship between nums and m:

// m[nums[i].first][nums[i].second] == i;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto result = m.find(val) == m.end();
        
        m[val].push_back(nums.size());
        nums.push_back(pair<int, int>(val, m[val].size() - 1));
        
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto result = m.find(val) != m.end();
        if(result)
        {
            auto last = nums.back();
            m[last.first][last.second] = m[val].back();
            nums[m[val].back()] = last;
            m[val].pop_back();
            if(m[val].empty()) m.erase(val);
            nums.pop_back();
        }
        return result;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> m;
};
