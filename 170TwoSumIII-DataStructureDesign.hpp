// 170 Two Sum III - Data structure design

// Design and implement a TwoSum class. It should support the following operations: add and find.

// add - Add the number to an internal data structure.
// find - Find if there exists any pair of numbers which sum is equal to the value.

// For example,
// add(1); add(3); add(5);
// find(4) -> true
// find(7) -> false

class TwoSum {
public:
    
    // Add the number to an internal data structure.
    void add(int number) {
        ++nums[number];
    }
    
    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for(auto & nValue : nums){
            int i = value - nValue.first;
            int c = nums.count(i)?nums[i]:0;
            if (c &&(i != nValue.first || c > 2) return true;
        }
        return false;
    }
private:
    unordered_map<int, int> nums;
};

// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);