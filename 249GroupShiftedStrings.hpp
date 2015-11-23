// 249 Group Shifted Strings

// Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

// "abc" -> "bcd" -> ... -> "xyz"
// Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

// For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
// Return:

// [
//   ["abc","bcd","xyz"],
//   ["az","ba"],
//   ["acef"],
//   ["a","z"]
// ]
// Note: For the return value, each inner list's elements must follow the lexicographic order.

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, multiset<string>> m;
        for(auto && str : strings){
            m[keyForString(str)].insert(str);
        }
        vector<vector<string>> result;
        for(auto && group:m){
            result.emplace_back(vector<string>(group.second.begin(), group.second.end()));
        }
        return result;
    }
private:
    string keyForString(string str){
        if(str.empty()) return str;
        for(int i = 1; i < str.size(); i++){
            str[i] = 'a' + str[i] - str[0];
            if(str[i] < 'a') str[i] += 26;
        }
        str[0] = 'a';
        return str;
    }
};