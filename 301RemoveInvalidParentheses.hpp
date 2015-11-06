// 301 Remove Invalid Parentheses

// Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

// Note: The input string may contain letters other than the parentheses ( and ).

// Examples:
// "()())()" -> ["()()()", "(())()"]
// "(a)())()" -> ["(a)()()", "(a())()"]
// ")(" -> [""]

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        finalList.clear();
        filter.clear();
        minDeleted = INT_MAX;
        DFS(s, 0);
        return finalList;
    }
    
private:
    void DFS(string s, int nDeleted) {
        if(nDeleted > minDeleted) return;
        if(filter.count(s)) return;
        filter.insert(s);
        if(isValid(s)){
            if(nDeleted < minDeleted) {finalList.clear(); minDeleted = nDeleted;}
            finalList.push_back(s);
            return;
        }
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '(' || s[i] == ')') DFS(s.substr(0, i) + s.substr(i + 1), nDeleted + 1);
    }
    
    bool isValid(string &s) {
        int openRemaind = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') ++openRemaind;
            else if(s[i] == ')' && --openRemaind < 0) return false;
        }
        return !openRemaind;
    }
    
    vector<string> finalList;
    unordered_set<string> filter;
    int minDeleted;
};