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

// https://leetcode.com/discuss/81478/easy-short-concise-and-fast-java-dfs-3-ms-solution

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        DFS(s, 0, 0, false, ans);
        return ans;
    }
    
    //we need to keep another information: the last removal position. 
    // If we do not have this position, we will generate duplicate by 
    // removing two ‘)’ in two steps only with a different order. 
    void DFS(string s, int cur, int lastDelete, int reversed, vector<string> &ans)
    {
        int nOpen = 0;
        char open = '(', close = ')';
        if(reversed) swap(open, close);
        for(int i = cur; i < (int)s.size(); i++){
            if(s[i] == open) ++nOpen;
            if(s[i] == close) --nOpen;
            if(nOpen < 0){
                for(int j = lastDelete; j <= i;j++){
                    if(s[j] == close && (j == lastDelete || s[j-1] != close))
                        DFS(s.substr(0,j) + s.substr(j+1), i, j, reversed, ans);
                }
                return;
            }
        }
        
        string reversedS(s.rbegin(), s.rend());
        if(reversed){
            ans.emplace_back(reversedS);
        }
        else {
            DFS(reversedS, 0, 0, true, ans);
        }
    }
};