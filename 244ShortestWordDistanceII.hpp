// 244 Shortest Word Distance II
// This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

// Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

// For example,
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Given word1 = “coding”, word2 = “practice”, return 3.
// Given word1 = "makes", word2 = "coding", return 1.

// Note:
// You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); i++) m[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        auto &v1 = m[word1];
        auto &v2 = m[word2];
        int diff = INT_MAX;
        auto it1 = v1.begin(), it2 = v2.begin();
        while(it1 != v1.end() && it2 != v2.end()){
            if(*it1 < *it2){
                diff = min(diff, *it2 - *it1);
                ++it1;
            }else {
                diff = min(diff, *it1 - *it2);
                ++it2;
            }
        }
        return diff;
    }
private:
    unordered_map<string,vector<int>> m;
};

