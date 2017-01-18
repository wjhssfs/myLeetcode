// 267 Palindrome Permutation II
// Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

// For example:

// Given s = "aabb", return ["abba", "baab"].

// Given s = "abc", return [].

// Hint:

// If a palindromic permutation exists, we just need to generate the first half of the string.
// To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> m;
        vector<string> results;
        for(char c : s) ++m[c];
        bool firstOdd = false;
        char oddC = 0;
        for(auto cE : m){
            if(cE.second%2){
                if(firstOdd || !(s.size()%2)) return results;
                firstOdd = true;
                oddC = cE.first;
            }
        }
        if(s.size()%2 && !firstOdd) return results;
        
        string buf(s.size(), 0);
        if(s.size()%2) {
            buf[(buf.size()-1)/2] = oddC;
            --m[oddC];
        }
        
        gen(m, buf, 0, s.size(), results);
        return results;
    }
    
private:
    void gen(unordered_map<char, int> &m, string &buf, int cur, int total, vector<string> &results){
         if(cur == total/2) {
            results.push_back(buf);
            return;
        }
        for(auto & cE : m){
            if(cE.second){
                buf[cur] = buf[total - 1 - cur] = cE.first;
                cE.second -= 2;
                gen(m, buf, cur+1, total, results);
                cE.second += 2;
            }
        }
    }
};