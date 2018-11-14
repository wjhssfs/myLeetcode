// 140 Word Break II
// Given a string s and a dictionary of words dict, add spaces in s to construct a
// sentence where each word is a valid dictionary word.
// Return all such possible sentences.
// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].
// A solution is ["cats and dog", "cat sand dog"].

class Solution {
    void dfs(vector<unordered_set<string>>& dp, int cur, string str, vector<string>& res) {
        if (cur == 0) {
            res.push_back(str);
            return;
        }
        for (auto&& e : dp[cur]) {
            dfs(dp, cur - e.size(), e + string(!!str.size(), ' ') + str, res);
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> res;
        vector<unordered_set<string>> dp(s.size() + 1);
        dp[0].insert("");
        for (int i = 1; i <= s.size(); ++i) {
            for (auto&& word : dict) {
                if (i >= word.size()) 
                    if (dp[i - word.size()].size() && word == s.substr(i - word.size(), word.size()))
                        dp[i].insert(word);
            }
        }
        dfs(dp, s.size(), "", res);
        return res;
    }
};

class Solution {
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if(dict.count(s)){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(dict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,dict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        m[s]=result; //memorize
        return result;
    }
};

public class Solution {
public List<String> wordBreak(String s, Set<String> dict) {
    List<String> result = new ArrayList<String>();
    for(int j = s.length() - 1; j >= 0; j--){
        if(dict.contains(s.substring(j)))// optimization, it needs to end with a word in dict
            break;
        else{
            if(j == 0)
                return result;
        }
    }
    for(int i = 0; i < s.length()-1; i++)
    {
        if(dict.contains(s.substring(0,i+1)))
        {
            List<String> strs = wordBreak(s.substring(i+1,s.length()),dict);
            if(strs.size() != 0)
                for(Iterator<String> it = strs.iterator();it.hasNext();)
                {
                    result.add(s.substring(0,i+1)+" "+it.next());
                }
        }
    }
    if(dict.contains(s)) result.add(s);
    return result;
}

 class Solution {
    public:
        // the run time is still 4ms even with hash 
        unordered_map<string , vector<string>> dpHash;

        // it runs 4ms. the key factor it that it checks from both side to filter 
        // out impossible combination in every early stage
        vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
            vector<string> res; 
            // check hash first 
            if (dpHash.find(s) != dpHash.end()) {
                return dpHash[s];
            }

            // check if need go further
            // it there's no checking here, the run time will be 
            // wi hash : 20ms
            // wo hash : TLE
            bool notFound = true;
            for (int i = s.size() - 1; i >=0; --i) {   // key here
                if (wordDict.find(s.substr(i)) != wordDict.end()) {
                    notFound = false;
                    break;
                } 
            }
            if (notFound) { return res; }

            // go further 
            if (wordDict.find(s) != wordDict.end()) { res.push_back(s); }
            for (int i = s.size() - 2; i >= 0; --i) {
                if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
                    vector<string> subRes = wordBreak(s.substr(i + 1), wordDict);
                    for (auto tmp : subRes) {
                        res.push_back(s.substr(0, i + 1) + " " + tmp);
                    }
                } 
            }

            dpHash[s] = res;  // update hash
            return res;
        }
};
