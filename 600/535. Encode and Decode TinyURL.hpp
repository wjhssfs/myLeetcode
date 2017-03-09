// 535. Encode and Decode TinyURL

// TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

// Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        urls.emplace_back(longUrl);
        return to_string(urls.size()-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int i = stoi(shortUrl);
        return urls[i];
    }
private:
    vector<string> urls;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));