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
    void DFS(string s, int cur, int lastDelete, bool reversed, vector<string> &ans)
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
                return; // recursion above should generate all results. so need to exit here.
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

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
      queue<tuple<string,int,int,char>> q;
        q.push(make_tuple(s,0,0,'('));
        vector<string> res;
        while(!q.empty()) {
            auto t=q.front();
            q.pop();
            string str=get<0>(t);
            int start =get<1>(t), lastRm=get<2>(t), count = 0;
            char l = get<3>(t), r = l=='('?')':'(';
            for(int i=start; i<str.size();i++) {
                if(str[i] == l) count++;
                else if(str[i]==r) count--;
                if(count>=0) continue;
                for(int j=lastRm;j<=i;j++)
                    if(str[j]==r && (j==lastRm || str[j-1]!=r))
                        q.push(make_tuple(str.substr(0,j)+str.substr(j+1),i,j,l));
                break;
            }
            if(count < 0) continue;
            reverse(str.begin(),str.end());
            if(l=='(') q.push(make_tuple(str,0,0,')'));
            else res.push_back(str);
        }
        return res;
    }
};

class Solution {
    bool isValid(const string & s) {
        int open = 0;
        for (auto c : s) {
            if (c == '(') ++open;
            else if (c == ')') --open;
            if (open < 0) return false;
        }
        return open == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited;
        queue<string> q;
        q.emplace(s);
        bool found = false;
        while (!q.empty()) {
            int qsz = q.size();
            for (int sz = 0; sz < qsz; ++sz) {
                auto front = q.front(); q.pop();
                if (isValid(front)) {
                    res.emplace_back(front);
                    found = true;
                }
                if (found) continue;
                for (int i = 0; i < front.size(); ++i) {
                    if (front[i] != '(' && front[i] != ')') continue;
                    auto t = front.substr(0, i) + front.substr(i + 1);
                    if (visited.count(t))continue;
                    visited.emplace(t);
                    q.emplace(t);
                }
            }
        }
        return res;
    }
};