// 126 Word Ladder II 
// Given two words (start and end), and a dictionary, find all shortest transformation
// sequence(s) from start to end, such that: 
// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,
// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// Return
//   [
//     ["hit","hot","dot","dog","cog"],
//     ["hit","hot","lot","log","cog"]
//   ]
// Note:
// All words have the same length.
// All words contain only lowercase alphabetic characters.

class Solution {
    void dfs(unordered_map<string, unordered_set<string>>& g, string& endWord, vector<vector<string>>& res, vector<string>& cur) {
        for (auto&& next : g[cur.back()]) {
            cur.push_back(next);
            next == endWord ? (void)res.push_back(cur) : (void)dfs(g, endWord, res, cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()); dict.erase(beginWord);
        unordered_map<string, unordered_set<string>> g;
        queue<string> q; q.push(beginWord);
        bool ended = false;
        while (!q.empty() && !ended) {
            queue<string> nq;
            unordered_set<string> filter;
            while (!q.empty()) {
                auto org = q.front(); q.pop();
                for (int i = 0; i < org.size(); ++i) {
                    auto cur = org;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == org[i]) continue;
                        cur[i] = c;
                        if (dict.count(cur) == 0) continue;
                        g[org].insert(cur);
                        if (cur == endWord) ended = true;
                        else {
                            filter.insert(cur);
                            nq.push(cur); 
                        }
                    }
                }
            }
            for (auto &&w : filter) dict.erase(w);
            swap(q, nq);
        }
        vector<vector<string>> res; if (!ended) return res;
        vector<string> cur = {beginWord};
        dfs(g, endWord, res, cur);
        return res;
    }
};


class Solution2 {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        map<string, vector<string>> traces; // If A->C and B->C, then traces[C] contains A and B.
                                            // This is used for recovering the paths.
        vector<unordered_set<string>> level(2);
        int cur = 0;
        int prev = 1;
        level[cur].insert(start);
        dict.insert(end);

        while (true)
        {
            prev = !prev;
            cur = !cur;
            level[cur].clear();

            // remove visited words. IMPORTANT!
            for (unordered_set<string>::iterator it = level[prev].begin(); it != level[prev].end(); ++it)
                dict.erase(*it);

            for (unordered_set<string>::iterator it = level[prev].begin(); it != level[prev].end(); ++it)
            {
                string word = *it;
                for (size_t i = 0; i < word.size(); i++) {
                    char before = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == before)
                            continue;
                        word[i] = c;
                        if (dict.find(word) != dict.end()) {
                            traces[word].push_back(*it);
                            level[cur].insert(word);
                        }
                    }
                    word[i] = before;
                }
            }

            if (level[cur].empty() || level[cur].count(end) > 0)
                break;
        }

        vector<vector<string>> res;
        vector<string> onePath;
        if (!traces.empty())
            buildResult(traces, res, onePath, end);

        return res;
    }

    void buildResult(
    	map<string, vector<string>> &traces,
     	vector<vector<string>> &res, vector<string> &onePath, string word
     	)
    {
        if (traces.count(word) == 0)
        {
            vector<string> copy(onePath);
            copy.push_back(word);
            reverse(copy.begin(), copy.end());
            res.push_back(copy);
            return;
        }

        const vector<string> &s = traces[word];
        onePath.push_back(word);
        for (vector<string>::const_iterator it = s.begin(); it != s.end(); ++it)
            buildResult(traces, res, onePath, *it);
        onePath.pop_back();
    }
};


// https://leetcode.com/discuss/41689/88ms-accepted-solution-with-68ms-word-ladder-88ms-word-ladder
class Solution {
public:
    std::vector<std::vector<std::string> > findLadders(
    	std::string beginWord, std::string endWord,
    	std::unordered_set<std::string> &dict
    	)
    {
        std::vector<std::vector<std::string> > paths;
        std::vector<std::string> path(1, beginWord);
        if (beginWord == endWord) {
            paths.push_back(path);
            return paths;
        }
        std::unordered_set<std::string> words1, words2;
        words1.insert(beginWord);
        words2.insert(endWord);
        std::unordered_map<std::string, std::vector<std::string> > nexts;
        bool words1IsBegin = false;
        if (findLaddersHelper(words1, words2, dict, nexts, words1IsBegin))
            getPath(beginWord, endWord, nexts, path, paths);
        return paths;
    }
private:
    bool findLaddersHelper(
        std::unordered_set<std::string> &words1,
        std::unordered_set<std::string> &words2,
        std::unordered_set<std::string> &dict,
        std::unordered_map<std::string, std::vector<std::string> > &nexts,
        bool &words1IsBegin)
    {
        words1IsBegin = !words1IsBegin;
        if (words1.empty())
            return false;
        if (words1.size() > words2.size())
            return findLaddersHelper(words2, words1, dict, nexts, words1IsBegin);
        for (auto it = words1.begin(); it != words1.end(); ++it)
            dict.erase(*it);
        for (auto it = words2.begin(); it != words2.end(); ++it)
            dict.erase(*it);
        std::unordered_set<std::string> words3;
        bool reach = false;
        for (auto it = words1.begin(); it != words1.end(); ++it) {
            std::string word = *it;
            for (auto ch = word.begin(); ch != word.end(); ++ch) {
                char tmp = *ch;
                for (*ch = 'a'; *ch <= 'z'; ++(*ch))
                    if (*ch != tmp) // not neccessary since it has been erased from dict
                        if (words2.find(word) != words2.end()) {
                            reach = true;
                            words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                        }
                        else if (!reach && dict.find(word) != dict.end()) {
                            words3.insert(word);
                            words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                        }
                *ch = tmp;
            }
        }
        return reach || findLaddersHelper(words2, words3, dict, nexts, words1IsBegin);
    }
    void getPath(
        std::string beginWord,
        std::string &endWord,
        std::unordered_map<std::string, std::vector<std::string> > &nexts,
        std::vector<std::string> &path,
        std::vector<std::vector<std::string> > &paths) {
        if (beginWord == endWord)
            paths.push_back(path);
        else
            for (auto it = nexts[beginWord].begin(); it != nexts[beginWord].end(); ++it) {
                path.push_back(*it);
                getPath(*it, endWord, nexts, path, paths);
                path.pop_back();
            }
    }
};