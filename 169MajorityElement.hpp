// 169 Majority Element
// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
// You may assume that the array is non-empty and the majority element always exist in the array.

class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int, int> m;
        for_each(num.begin(), num.end(), [&](int a){m[a]++; });
        auto r = find_if(m.begin(), m.end(), [&](map<int, int>::value_type & v){return v.second > num.size() / 2; });
        return r->first;
    }
};
