// 288 Unique Word Abbreviation
// An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

// a) it                      --> it    (no abbreviation)

//      1
// b) d|o|g                   --> d1g

//               1    1  1
//      1---5----0----5--8
// c) i|nternationalizatio|n  --> i18n

//               1
//      1---5----0
// d) l|ocalizatio|n          --> l10n
// Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

// Example: 
// Given dictionary = [ "deer", "door", "cake", "card" ]

// isUnique("dear") -> false
// isUnique("cart") -> true
// isUnique("cane") -> false
// isUnique("make") -> true

class ValidWordAbbr {
public:
	ValidWordAbbr(vector<string> &dictionary) {
		s = dictionary;
	}

	bool isUnique(string word) {
		for (auto && wordInDic : s){
			if (wordInDic == word) continue;
			if (word.size() == wordInDic.size() && word.size() > 0 && word[0] == wordInDic[0] && *word.rbegin() == *wordInDic.rbegin()) return false;
		}
		return true;
	}
	vector<string> s;
};

// Faster
class ValidWordAbbr {
public:
	ValidWordAbbr(vector<string> &dictionary) :
		m(vector<vector<map<int, set<string>>>>(26, vector<map<int, set<string>>>(26)))
	{
		for (auto && word : dictionary)
			if(!word.empty()) m[*word.begin() - 'a'][*word.rbegin() - 'a'][word.size()].insert(word);
	}

	bool isUnique(string word) {
		if (word.empty()) return true;
		for (auto && wInD : m[*word.begin() - 'a'][*word.rbegin() - 'a'][word.size()])
			if (wInD != word) return false;
		return true;
	}

private:
	vector<vector<map<int, set<string>>>> m;
};

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string& d : dictionary) {
            int n = d.length();
            string abbr = d[0] + to_string(n) + d[n - 1]; // can just use to_string(n)
            mp[abbr].insert(d);
        }
    }

    bool isUnique(string word) {
        int n = word.length();
        string abbr = word[0] + to_string(n) + word[n - 1];
        return mp[abbr].count(word) == mp[abbr].size(); 
    }
private:
    unordered_map<string, unordered_set<string>> mp;
};

