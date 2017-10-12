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


// https://discuss.leetcode.com/topic/81637/two-solutions-and-thoughts
class Codec:
    alphabet = string.ascii_letters + '0123456789'

    def __init__(self):
        self.url2code = {}
        self.code2url = {}

    def encode(self, longUrl):
        while longUrl not in self.url2code:
            code = ''.join(random.choice(Codec.alphabet) for _ in range(6))
            if code not in self.code2url:
                self.code2url[code] = longUrl
                self.url2code[longUrl] = code
        return 'http://tinyurl.com/' + self.url2code[longUrl]

    def decode(self, shortUrl):
        return self.code2url[shortUrl[-6:]]