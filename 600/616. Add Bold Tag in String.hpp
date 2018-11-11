// 616. Add Bold Tag in String
// Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

// Example 1:
// Input: 
// s = "abcxyz123"
// dict = ["abc","123"]
// Output:
// "<b>abc</b>xyz<b>123</b>"
// Example 2:
// Input: 
// s = "aaabbcc"
// dict = ["aaa","aab","bc"]
// Output:
// "<b>aaabbc</b>c"
// Note:
// The given dict won't contain duplicates, and its length won't exceed 100.
// All the strings in input have length in range [1, 1000].

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        string res;
        for (int i = 0, bs = 0, be = -1; i <= s.size(); ++i) {
            for (int j = 0; j < dict.size(); ++j) {
                if ( i + dict[j].size() <= s.size() && s.substr(i, dict[j].size()) == dict[j]) {
                    be = max(be, i + (int)dict[j].size() - 1);
                }
            }
            if (i > be) {
                if (be != -1) res += "<b>" + s.substr(bs, be - bs + 1) + "</b>";
                if (i < s.size()) res += s[i];
                bs = i + 1; // +1 since s[i] can't be bolded
                be = -1;
            }
        }
        return res;
    }
};

public class Solution {
    public String addBoldTag(String s, String[] dict) {
        boolean[] bold = new boolean[s.length()];
        for (int i = 0, end = 0; i < s.length(); i++) {
            for (String word : dict) {
                if (s.startsWith(word, i)) {
                    end = Math.max(end, i + word.length());
                }
            }
            bold[i] = end > i;
        }
        
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (!bold[i]) {
                result.append(s.charAt(i));
                continue;
            }
            int j = i;
            while (j < s.length() && bold[j]) j++;
            result.append("<b>" + s.substring(i, j) + "</b>");
            i = j - 1;
        }
        
        return result.toString();
    }
}